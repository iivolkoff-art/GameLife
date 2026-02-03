#include <chrono>
#include <thread>
#include "GameLife.h"
#include <iostream>


GameLife::GameLife(GameGrid gr, std::unique_ptr<IRuleStrategy> rl, std::unique_ptr<IRenderer> rnd, //DefaultGame
                   std::unique_ptr<IWriter<std::string>> wrt,
                   std::unique_ptr<IParser<std::string, std::vector<std::vector<bool>>>> rp,
                   const ConfigStruct::Simulation& smstr, std::vector<std::unique_ptr<IGameEvent>> evnt)
    : grid(std::move(gr)), rules(std::move(rl)), renderer(std::move(rnd)), writer(std::move(wrt)),
    resultParser(std::move(rp)), simulationData(smstr), events(std::move(evnt))
{

}

// GameLife::GameLife(GameGrid gr, std::unique_ptr<IRuleStrategy> rl, std::unique_ptr<IRenderer> rnd, //AirStrike
//                    std::unique_ptr<IWriter<std::string>> wrt,
//                    std::unique_ptr<IParser<std::string, std::vector<std::vector<bool>>>> rp,
//                    const AirStrikeConfigStruct::Simulation& smstr, std::vector<std::unique_ptr<IGameEvent>> evnt)
//     : grid(std::move(gr)), rules(std::move(rl)), renderer(std::move(rnd)), writer(std::move(wrt)),
//     resultParser(std::move(rp)), simulationData(smstr), events(std::move(evnt))
// {

// }

void GameLife::update() {
    GameGrid nextGrid(grid.getRows(), grid.getCols());

    for (uint8_t i = 0; i < grid.getRows(); ++i) {
        for (uint8_t j = 0; j < grid.getCols(); ++j) {
            uint8_t count = grid.countNeighbors(i, j);
            bool currentState = grid.getCell(i, j);
            bool nextState = rules->willBeAlive(currentState, count);

            nextGrid.setCell(i, j, nextState);
        }
    }

    grid = nextGrid;
}

void GameLife::run() {
    for(uint16_t i = 0; i < simulationData.cycles; i++) {
        update();
        for (auto& event : events) {
            event->execute(grid, i);
        }
        //renderer->render(grid.getCells()); //CMDPrint
        writer->write(resultParser->parse(grid.getCells()));
        emit mapUpdated();
        if(!hasAnyLife()) break;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / simulationData.fps));
    }
}

const GameGrid& GameLife::GetGrid(){
    return grid;
}


bool GameLife::hasAnyLife() const{
    for(const auto& r: grid.getCells()){
        for(const bool& c: r){
            if(c) return true;
        }
    }
    return false;
}
