#include <memory>
#include <unistd.h>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include "./Model/Render/ConsoleRender.h"
#include "./Model/Rules/StandartRule.h"
#include "./Model/GameGrid/GameGrid.h"
#include "./Model/MainClass/GameLife.h"

#include "./Model/Reader/IReader.h"
#include "./Model/Reader/DefaultReader.h"

#include "./Model/Parser/IParser.h"
#include "./Model/Parser/StrJONParser.h"
#include "./Model/Parser/JSONConfigStructParser.h"
#include "./Model/Parser/AirStrikeJSONConfigStructParser.h"

#include "./Model/ConfigStruct.h" //DefaultGame
//#include "./Model/AirStrikeConfigStruct.h" //AirStrike

#include "./Model/FileWriter/DefaultWriter.h"
#include "./Model/Parser/VectVectBoolResultParser.h"

#include "./ViewModel/GameLifeViewModel.h"

#include "./Model/Events/IGameEvent.h"
//#include "./Model/Events/AirstrikeEvent.h" //AirStrike



void addMapObject(GameGrid& grid, const std::vector<std::string>& cell){
    for(uint8_t i = 0; i < cell.size(); i++){
        for(uint8_t j = 0; j < cell[i].size(); j++){
            if(cell[i][j] == '*'){
                grid.setCell(i, j, true);
            }
        }
    }
}


void printUsage(const std::string& inputFile, const std::string& outputFile) {
    std::cout << "  -i <file>    Specify the input file. Default: " << inputFile << std::endl;
    std::cout << "  -o <file>    Specify the output file. Default: " << outputFile << std::endl;
}


void checkInputData(const ConfigStruct& config) { //DefaultGame
//void checkInputData(const AirStrikeConfigStruct& config) { //AirStrike
    const auto& world = config.world;
    const auto& sim = config.simulation;
    //const auto& airStr = config.airstrikeSettings; //AirStrike

    if(world.width == 0) throw std::runtime_error("Width must be > 0");
    if(world.height == 0) throw std::runtime_error("Height must be > 0");
    if(sim.fps == 0) throw std::runtime_error("FPS must be > 0");

    if(world.height != world.cells.size()) {
        throw std::runtime_error("Height doesn't match number of rows");
    }

    for(uint8_t i = 0; i < world.cells.size(); ++i) {
        if(world.width != world.cells[i].size()) {
            throw std::runtime_error("Row " + std::to_string(i) +
                                     " has incorrect width");
        }

        for(uint8_t j = 0; j < world.cells[i].size(); ++j) {
            char cell = world.cells[i][j];
            if(cell != '.' && cell != '*') {
                throw std::runtime_error("Invalid character at position (" +
                                         std::to_string(i) + "," +
                                         std::to_string(j) + ")");
            }
        }
    }

        // for(uint32_t i = 0; i < airStr.strikes.size(); i++){ //AirStrike
        //     if(airStr.strikes[i].cycle > sim.cycles) throw std::runtime_error("Air strike cycle exceeds simulation duration");
        //     if (airStr.strikes[i].row == 0 || airStr.strikes[i].row > world.height)
        //         throw std::runtime_error("Air strike row index out of range (must be 1 to " + std::to_string(world.height) + ")");
        //     if (airStr.strikes[i].col == 0 || airStr.strikes[i].col > world.width)
        //         throw std::runtime_error("Air strike column index out of range (must be 1 to " + std::to_string(world.width) + ")");

        // }
}


int main(int argc, char *argv[])
{
    int8_t opt;
    std::string inputFile = "game_of_life_input.json";
    std::string outputFile = "game_of_life_output.json";

    while ((opt = getopt(argc, argv, "i:o:")) != -1) {
        switch (opt) {
        case 'i':
            inputFile = optarg;
            break;
        case 'o':
            outputFile = optarg;
            break;
        case 'h':
            printUsage(inputFile, outputFile);
            break;
        default:
            std::cerr << "Unknown option: " << static_cast<char>(optopt) << std::endl;
            printUsage(inputFile, outputFile);
            return 1;
        }
    }


    ConfigStruct configData; //DefaultGame
    //AirStrikeConfigStruct configData; // AirStrike

    {
        std::unique_ptr<IReader<std::string>> reader = std::make_unique<DefaultReader>();
        std::unique_ptr<IParser<QJsonObject, std::string>> strJsonParser = std::make_unique<StrJONParser>();

        std::unique_ptr<IParser<ConfigStruct, QJsonObject>> jsonStructParser = std::make_unique<JSONConfigStructParser>(); //DefaultGame
        //std::unique_ptr<IParser<AirStrikeConfigStruct, QJsonObject>> jsonStructParser = std::make_unique<AirStrikeJSONConfigStructParser>(); // AirStrike

        auto jsonData = strJsonParser->parse(reader->read(inputFile));
        configData = jsonStructParser->parse(jsonData);
    }

    checkInputData(configData);
    uint8_t rows = configData.world.height;
    uint8_t cols = configData.world.width;

    GameGrid myGrid(rows, cols);

    addMapObject(myGrid, configData.world.cells);


    auto rules = std::make_unique<StandartRule>();
    auto renderer = std::make_unique<ConsoleRender>();
    auto writer = std::make_unique<DefaultWriter>();
    auto resultParser = std::make_unique<VectVectBoolResultParser>();

    std::vector<std::unique_ptr<IGameEvent>> events;
    //events.push_back(std::make_unique<AirstrikeEvent>(configData.airstrikeSettings)); // AirStrike

    writer->setPath(outputFile);

    GameLife game(std::move(myGrid), std::move(rules), std::move(renderer), std::move(writer),
                  std::move(resultParser), configData.simulation, std::move(events));

    QGuiApplication app(argc, argv);
    GameLifeViewModel gameLifeViewModel(&game);
    QQmlApplicationEngine qmlEngine;
    qmlEngine.rootContext()->setContextProperty("myLifeModel", &gameLifeViewModel);
    QObject::connect(
        &qmlEngine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    qmlEngine.loadFromModule("GameLife", "Main");


    std::thread gameThread([&game]() {
        game.run();
    });
    gameThread.detach();


    return app.exec();
}
