#ifndef GAMELIFE_H
#define GAMELIFE_H

#include <memory>
#include <string>
#include <vector>
#include <QObject>

#include "../GameGrid/GameGrid.h"
#include "../Rules/IRuleStrategy.h"
#include "../Render/IRenderer.h"
#include "../FileWriter/IWriter.h"
#include "../Parser/IParser.h"
#include "../ConfigStruct.h" //DefaultGame
//#include "../AirStrikeConfigStruct.h" //AirStrike
#include "../Events/IGameEvent.h"


class GameLife : public QObject {
    Q_OBJECT
private:
    GameGrid grid;
    std::unique_ptr<IRuleStrategy> rules;
    std::unique_ptr<IRenderer> renderer;
    std::unique_ptr<IWriter<std::string>> writer;
    std::unique_ptr<IParser<std::string, std::vector<std::vector<bool>>>> resultParser;
    ConfigStruct::Simulation simulationData; //DefaultGame
    //AirStrikeConfigStruct::Simulation simulationData; //AirStrike
    std::vector<std::unique_ptr<IGameEvent>> events;

public:
    GameLife(GameGrid gr, std::unique_ptr<IRuleStrategy> rl, std::unique_ptr<IRenderer> rnd, //DefaultGame
             std::unique_ptr<IWriter<std::string>> wrt, std::unique_ptr<IParser<std::string, std::vector<std::vector<bool>>>> rp,
                const ConfigStruct::Simulation& smstr, std::vector<std::unique_ptr<IGameEvent>> evnt);

    // GameLife(GameGrid gr, std::unique_ptr<IRuleStrategy> rl, std::unique_ptr<IRenderer> rnd, //AirStrike
    //          std::unique_ptr<IWriter<std::string>> wrt, std::unique_ptr<IParser<std::string, std::vector<std::vector<bool>>>> rp,
    //          const AirStrikeConfigStruct::Simulation& smstr, std::vector<std::unique_ptr<IGameEvent>> evnt);

    void update();
    void run();
    const GameGrid& GetGrid();

protected:
    bool hasAnyLife() const;

signals:
    void mapUpdated();
};

#endif // GAMELIFE_H
