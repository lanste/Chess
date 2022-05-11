Application.o: src/Application.cpp src/Application.h src/UI/UIManager.h \
 src/MainMenu.h src/UI/ITerminal.h src/Game.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/Players/LocalPlayer.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/ProgramOptions.h
Game.o: src/Game.cpp src/Game.h src/UI/UIManager.h src/UI/ITerminal.h \
 src/Boards/Board.h src/Boards/../Players/Player.h \
 src/Players/LocalPlayer.h src/Players/AI1.h src/Players/AI2.h \
 src/Players/AI3.h
main.o: src/main.cpp src/Application.h src/UI/UIManager.h src/MainMenu.h \
 src/UI/ITerminal.h src/Game.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/Players/LocalPlayer.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/ProgramOptions.h
MainMenu.o: src/MainMenu.cpp src/MainMenu.h src/UI/UIManager.h \
 src/UI/ITerminal.h src/Game.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/Players/LocalPlayer.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h
ProgramOptions.o: src/ProgramOptions.cpp src/ProgramOptions.h \
 src/UI/UIManager.h src/UI/ITerminal.h
