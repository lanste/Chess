CXX= g++
CXXFLAGS= -std=c++17 -Wall -pedantic
LD= g++
LDFLAGS= -pedantic
MODULES = AI1.o AI2.o AI3.o Application.o BackCmd.o Bishop.o ChessSetupMenu.o ChoosePlayerCmd.o ClassicalChessBoard.o ComingSoonCmd.o ExitCmd.o Game.o ITerminal.o King.o Knight.o LaunchGameCmd.o LoadGameCmd.o LoadGameMenu.o LocalPlayer.o MainMenu.o MenuLoadOptionCmd.o MenuStartOptionCmd.o OnlinePlayer.o Pawn.o Piece.o ProgramOptions.o Queen.o Rook.o SaveGameCmd.o SaveManager.o SetupGameCmd.o StartGameMenu.o main.o
PROGRAM := lanskteo-chess
SOURCE_DIR := src
DOC_DIR := doc

all: compile doc cleanup
compile: $(MODULES)
	$(CXX) $(CXXFLAGS) $(MODULES) -o $(PROGRAM)
run: compile cleanup
	./$(PROGRAM) -t
doc:
	- doxygen
	ln -s $(DOC_DIR)/html/index.html Documentation.html
terminal: compile clean
	./$(PROGRAM) -t
dep:
	$(CXX) -MM src/*.cpp >>Makefile
cleanup:
	- rm -rf *.o
clean:
	- rm -rf *.o
	- rm -rf $(PROGRAM)
	- rm -rf doc
	-rm Documentation.html
purge:
	- rm -rf *.o
	- rm -rf $(PROGRAM)
	- rm -rf doc
	- rm -rf saves
%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
AI1.o: src/AI1.cpp src/AI1.h src/Player.h src/Interface.h src/ITerminal.h
AI2.o: src/AI2.cpp src/AI2.h src/Player.h src/Interface.h src/ITerminal.h
AI3.o: src/AI3.cpp src/AI3.h src/Player.h src/Interface.h src/ITerminal.h
Application.o: src/Application.cpp src/Application.h src/Interface.h \
 src/MainMenu.h src/Menu.h src/ITerminal.h src/Command.h \
 src/MenuStartOptionCmd.h src/Game.h src/ClassicalChessBoard.h \
 src/Board.h src/Moves/ChessMove.h src/coordinates.h src/moveTypes.h \
 src/Piece.h src/King.h src/Queen.h src/Bishop.h src/Knight.h src/Rook.h \
 src/Pawn.h src/LocalPlayer.h src/Player.h src/AI1.h src/AI2.h src/AI3.h \
 src/BackCmd.h src/SaveManager.h src/StartGameMenu.h src/SetupGameCmd.h \
 src/ChessSetupMenu.h src/LaunchGameCmd.h src/ComingSoonCmd.h \
 src/MenuLoadOptionCmd.h src/LoadGameMenu.h src/LoadGameCmd.h \
 src/OnlinePlayer.h src/ExitCmd.h src/ProgramOptions.h
BackCmd.o: src/BackCmd.cpp src/BackCmd.h src/Command.h src/Interface.h \
 src/ITerminal.h
Bishop.o: src/Bishop.cpp src/Bishop.h src/Piece.h src/Interface.h \
 src/ITerminal.h src/coordinates.h
ChessSetupMenu.o: src/ChessSetupMenu.cpp src/ChessSetupMenu.h src/Menu.h \
 src/Interface.h src/ITerminal.h src/Command.h src/BackCmd.h \
 src/LaunchGameCmd.h src/Game.h src/ClassicalChessBoard.h src/Board.h \
 src/Moves/ChessMove.h src/coordinates.h src/moveTypes.h src/Piece.h src/King.h \
 src/Queen.h src/Bishop.h src/Knight.h src/Rook.h src/Pawn.h \
 src/LocalPlayer.h src/Player.h src/AI1.h src/AI2.h src/AI3.h \
 src/SaveManager.h
ChoosePlayerCmd.o: src/ChoosePlayerCmd.cpp src/ChoosePlayerCmd.h \
 src/Command.h src/Interface.h src/ITerminal.h
ClassicalChessBoard.o: src/ClassicalChessBoard.cpp \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/Interface.h src/ITerminal.h src/King.h \
 src/Queen.h src/Bishop.h src/Knight.h src/Rook.h src/Pawn.h
ComingSoonCmd.o: src/ComingSoonCmd.cpp src/ComingSoonCmd.h src/Command.h \
 src/Interface.h src/ITerminal.h
ExitCmd.o: src/ExitCmd.cpp src/ExitCmd.h src/Command.h src/Interface.h \
 src/ITerminal.h
Game.o: src/Game.cpp src/Game.h src/ITerminal.h src/Interface.h \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/King.h src/Queen.h src/Bishop.h \
 src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h src/Player.h \
 src/AI1.h src/AI2.h src/AI3.h src/BackCmd.h src/Command.h \
 src/SaveManager.h
ITerminal.o: src/ITerminal.cpp src/ITerminal.h src/Interface.h
King.o: src/King.cpp src/King.h src/Piece.h src/Interface.h \
 src/ITerminal.h src/coordinates.h
Knight.o: src/Knight.cpp src/Knight.h src/Piece.h src/Interface.h \
 src/ITerminal.h src/coordinates.h
LaunchGameCmd.o: src/LaunchGameCmd.cpp src/LaunchGameCmd.h src/Command.h \
 src/Interface.h src/ITerminal.h src/Game.h src/ClassicalChessBoard.h \
 src/Board.h src/Moves/ChessMove.h src/coordinates.h src/moveTypes.h \
 src/Piece.h src/King.h src/Queen.h src/Bishop.h src/Knight.h src/Rook.h \
 src/Pawn.h src/LocalPlayer.h src/Player.h src/AI1.h src/AI2.h src/AI3.h \
 src/BackCmd.h src/SaveManager.h
LoadGameCmd.o: src/LoadGameCmd.cpp src/LoadGameCmd.h src/Command.h \
 src/Interface.h src/ITerminal.h src/LaunchGameCmd.h src/Game.h \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/King.h src/Queen.h src/Bishop.h \
 src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h src/Player.h \
 src/AI1.h src/AI2.h src/AI3.h src/BackCmd.h src/SaveManager.h \
 src/OnlinePlayer.h
LoadGameMenu.o: src/LoadGameMenu.cpp src/LoadGameMenu.h src/Menu.h \
 src/Interface.h src/ITerminal.h src/Command.h src/BackCmd.h \
 src/LoadGameCmd.h src/LaunchGameCmd.h src/Game.h \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/King.h src/Queen.h src/Bishop.h \
 src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h src/Player.h \
 src/AI1.h src/AI2.h src/AI3.h src/SaveManager.h src/OnlinePlayer.h
LocalPlayer.o: src/LocalPlayer.cpp src/LocalPlayer.h src/Player.h \
 src/Interface.h src/ITerminal.h
MainMenu.o: src/MainMenu.cpp src/MainMenu.h src/Menu.h src/Interface.h \
 src/ITerminal.h src/Command.h src/MenuStartOptionCmd.h src/Game.h \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/King.h src/Queen.h src/Bishop.h \
 src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h src/Player.h \
 src/AI1.h src/AI2.h src/AI3.h src/BackCmd.h src/SaveManager.h \
 src/StartGameMenu.h src/SetupGameCmd.h src/ChessSetupMenu.h \
 src/LaunchGameCmd.h src/ComingSoonCmd.h src/MenuLoadOptionCmd.h \
 src/LoadGameMenu.h src/LoadGameCmd.h src/OnlinePlayer.h src/ExitCmd.h
MenuLoadOptionCmd.o: src/MenuLoadOptionCmd.cpp src/MenuLoadOptionCmd.h \
 src/Command.h src/Interface.h src/ITerminal.h src/LoadGameMenu.h \
 src/Menu.h src/BackCmd.h src/LoadGameCmd.h src/LaunchGameCmd.h \
 src/Game.h src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h \
 src/coordinates.h src/moveTypes.h src/Piece.h src/King.h src/Queen.h \
 src/Bishop.h src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h \
 src/Player.h src/AI1.h src/AI2.h src/AI3.h src/SaveManager.h \
 src/OnlinePlayer.h
MenuStartOptionCmd.o: src/MenuStartOptionCmd.cpp src/MenuStartOptionCmd.h \
 src/Command.h src/Interface.h src/ITerminal.h src/Game.h \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/King.h src/Queen.h src/Bishop.h \
 src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h src/Player.h \
 src/AI1.h src/AI2.h src/AI3.h src/BackCmd.h src/SaveManager.h \
 src/StartGameMenu.h src/Menu.h src/SetupGameCmd.h src/ChessSetupMenu.h \
 src/LaunchGameCmd.h src/ComingSoonCmd.h
OnlinePlayer.o: src/OnlinePlayer.cpp src/OnlinePlayer.h src/Player.h \
 src/Interface.h src/ITerminal.h
Pawn.o: src/Pawn.cpp src/Pawn.h src/Piece.h src/Interface.h \
 src/ITerminal.h src/coordinates.h
Piece.o: src/Piece.cpp src/Piece.h src/Interface.h src/ITerminal.h \
 src/coordinates.h
ProgramOptions.o: src/ProgramOptions.cpp src/ProgramOptions.h \
 src/Interface.h src/ITerminal.h
Queen.o: src/Queen.cpp src/Queen.h src/Piece.h src/Interface.h \
 src/ITerminal.h src/coordinates.h
Rook.o: src/Rook.cpp src/Rook.h src/Piece.h src/Interface.h \
 src/ITerminal.h src/coordinates.h
SaveGameCmd.o: src/SaveGameCmd.cpp
SaveManager.o: src/SaveManager.cpp src/SaveManager.h
SetupGameCmd.o: src/SetupGameCmd.cpp src/SetupGameCmd.h src/Command.h \
 src/Interface.h src/ITerminal.h src/ClassicalChessBoard.h src/Board.h \
 src/Moves/ChessMove.h src/coordinates.h src/moveTypes.h src/Piece.h src/King.h \
 src/Queen.h src/Bishop.h src/Knight.h src/Rook.h src/Pawn.h src/Game.h \
 src/LocalPlayer.h src/Player.h src/AI1.h src/AI2.h src/AI3.h \
 src/BackCmd.h src/SaveManager.h src/ChessSetupMenu.h src/Menu.h \
 src/LaunchGameCmd.h
StartGameMenu.o: src/StartGameMenu.cpp src/StartGameMenu.h src/Menu.h \
 src/Interface.h src/ITerminal.h src/Command.h src/SetupGameCmd.h \
 src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h src/coordinates.h \
 src/moveTypes.h src/Piece.h src/King.h src/Queen.h src/Bishop.h \
 src/Knight.h src/Rook.h src/Pawn.h src/Game.h src/LocalPlayer.h \
 src/Player.h src/AI1.h src/AI2.h src/AI3.h src/BackCmd.h \
 src/SaveManager.h src/ChessSetupMenu.h src/LaunchGameCmd.h \
 src/ComingSoonCmd.h
main.o: src/main.cpp src/Application.h src/Interface.h src/MainMenu.h \
 src/Menu.h src/ITerminal.h src/Command.h src/MenuStartOptionCmd.h \
 src/Game.h src/ClassicalChessBoard.h src/Board.h src/Moves/ChessMove.h \
 src/coordinates.h src/moveTypes.h src/Piece.h src/King.h src/Queen.h \
 src/Bishop.h src/Knight.h src/Rook.h src/Pawn.h src/LocalPlayer.h \
 src/Player.h src/AI1.h src/AI2.h src/AI3.h src/BackCmd.h \
 src/SaveManager.h src/StartGameMenu.h src/SetupGameCmd.h \
 src/ChessSetupMenu.h src/LaunchGameCmd.h src/ComingSoonCmd.h \
 src/MenuLoadOptionCmd.h src/LoadGameMenu.h src/LoadGameCmd.h \
 src/OnlinePlayer.h src/ExitCmd.h src/ProgramOptions.h
