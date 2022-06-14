RESULT := lanskteo
SOURCE_DIR := src
DOC_DIR := doc
SAVES_DIR := saves
BUILD_DIR := build
DEP_FILE := dependecncies

CXX= g++
CXXFLAGS= -Wall -pedantic
LD= g++
LDFLAGS= -pedantic
EXT_LIB = -lstdc++fs
MODULES = $(BUILD_DIR)/AI1.o $(BUILD_DIR)/AI2.o $(BUILD_DIR)/AI3.o $(BUILD_DIR)/Application.o $(BUILD_DIR)/BackCmd.o \
		  $(BUILD_DIR)/Bishop.o $(BUILD_DIR)/ChessSetupMenu.o $(BUILD_DIR)/ChoosePlayerCmd.o $(BUILD_DIR)/ClassicalChessBoard.o \
		  $(BUILD_DIR)/ComingSoonCmd.o $(BUILD_DIR)/ExitCmd.o $(BUILD_DIR)/Game.o $(BUILD_DIR)/ITerminal.o $(BUILD_DIR)/King.o \
		  $(BUILD_DIR)/Knight.o $(BUILD_DIR)/LaunchGameCmd.o $(BUILD_DIR)/LoadGameCmd.o $(BUILD_DIR)/LoadGameMenu.o\
		  $(BUILD_DIR)/LocalPlayer.o $(BUILD_DIR)/MainMenu.o $(BUILD_DIR)/MenuLoadOptionCmd.o $(BUILD_DIR)/MenuStartOptionCmd.o\
		  $(BUILD_DIR)/OnlinePlayer.o $(BUILD_DIR)/Pawn.o $(BUILD_DIR)/Piece.o $(BUILD_DIR)/ProgramOptions.o $(BUILD_DIR)/Queen.o\
		  $(BUILD_DIR)/Rook.o $(BUILD_DIR)/SaveGameCmd.o $(BUILD_DIR)/SaveManager.o $(BUILD_DIR)/SetupGameCmd.o $(BUILD_DIR)/StartGameMenu.o\
		  $(BUILD_DIR)/main.o

all: compile doc
compile: $(RESULT)

run: compile $(RESULT)
	./$(RESULT) -t
doc:
	- doxygen
	#ln -s $(DOC_DIR)/index.html Documentation.html

#dep:
#	$(CXX) -MM src/*.cpp >>Makefile

clean:
	- rm -rf $(RESULT)
	- rm -rf $(BUILD_DIR)/*.o
	- rm -rf *.o
	- rm -rf $(BUILD_DIR)
	- rm -rf $(DOC_DIR)
	#-rm Documentation.html

purge:
	- rm -rf *.o
	- rm -rf $(RESULT)
	- rm -rf $(BUILD_DIR)/*.o
	- rm -rf *.o
	- rm -rf $(BUILD_DIR)
	- rm -rf $(DOC_DIR)
	- rm -rf $(SAVES_DIR) # !!! removes prepared saves

recompile: clean compile

$(BUILD_DIR):
	- mkdir $(BUILD_DIR)

$(RESULT): $(BUILD_DIR) $(MODULES)
	$(LD) $(LDFLAGS) $(MODULES) -o $(RESULT) $(EXT_LIB)

$(BUILD_DIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/*/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#$(BUILD_DIR)/%.o: src/*/*/%.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/AI1.o: src/Players/AI1.cpp src/Players/AI1.h src/Players/Player.h src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/AI2.o: src/Players/AI2.cpp src/Players/AI2.h src/Players/Player.h src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/AI3.o: src/Players/AI3.cpp src/Players/AI3.h src/Players/Player.h src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/Application.o: src/Application.cpp src/Application.h src/UI/Interface.h \
 src/Menus/MainMenu.h src/Menus/Menu.h src/UI/ITerminal.h src/Commands \
 src/Commands src/Game.h src/Boards/ClassicalChessBoard.h \
 src/Boards/Board.h src/Utility src/Utility/coordinates.h src/Utility/moveTypes.h \
 src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h \
 src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/Commands src/SaveManager.h src/Menus/StartGameMenu.h src/Commands \
 src/Menus/ChessSetupMenu.h src/Commands src/Commands \
 src/Commands src/Menus/LoadGameMenu.h src/Commands \
 src/Players/OnlinePlayer.h src/Commands src/ProgramOptions.h
$(BUILD_DIR)/BackCmd.o: src/Commands src/Commands src/Commands src/UI/Interface.h \
 src/UI/ITerminal.h
$(BUILD_DIR)/Bishop.o: src/Pieces/Bishop.cpp src/Pieces/Bishop.h src/Pieces/Piece.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Utility/coordinates.h
$(BUILD_DIR)/ChessSetupMenu.o: src/Menus/ChessSetupMenu.cpp src/Menus/ChessSetupMenu.h src/Menus/Menu.h \
 src/UI/Interface.h src/UI/ITerminal.h src/Commands src/Commands \
 src/Commands src/Game.h src/Boards/ClassicalChessBoard.h src/Boards/Board.h \
 src/Utility src/Utility/coordinates.h src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h \
 src/Pieces/Queen.h src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h \
 src/Players/LocalPlayer.h src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/SaveManager.h
$(BUILD_DIR)/ChoosePlayerCmd.o: src/Commands src/Commands \
 src/Commands src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/ClassicalChessBoard.o: src/Boards/ClassicalChessBoard.cpp \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/UI/Interface.h src/UI/ITerminal.h src/Pieces/King.h \
 src/Pieces/Queen.h src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h
$(BUILD_DIR)/ComingSoonCmd.o: src/Commands src/Commands src/Commands \
 src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/ExitCmd.o: src/Commands src/Commands src/Commands src/UI/Interface.h \
 src/UI/ITerminal.h
$(BUILD_DIR)/Game.o: src/Game.cpp src/Game.h src/UI/ITerminal.h src/UI/Interface.h \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h \
 src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/Commands src/Commands \
 src/SaveManager.h
$(BUILD_DIR)/ITerminal.o: src/UI/ITerminal.cpp src/UI/ITerminal.h src/UI/Interface.h
$(BUILD_DIR)/King.o: src/Pieces/King.cpp src/Pieces/King.h src/Pieces/Piece.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Utility/coordinates.h
$(BUILD_DIR)/Knight.o: src/Pieces/Knight.cpp src/Pieces/Knight.h src/Pieces/Piece.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Utility/coordinates.h
$(BUILD_DIR)/LaunchGameCmd.o: src/Commands src/Commands src/Commands \
 src/UI/Interface.h src/UI/ITerminal.h src/Game.h src/Boards/ClassicalChessBoard.h \
 src/Boards/Board.h src/Utility src/Utility/coordinates.h src/Utility/moveTypes.h \
 src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h \
 src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/Commands src/SaveManager.h
$(BUILD_DIR)/LoadGameCmd.o: src/Commands src/Commands src/Commands \
 src/UI/Interface.h src/UI/ITerminal.h src/Commands src/Game.h \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h \
 src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/Commands src/SaveManager.h \
 src/Players/OnlinePlayer.h
$(BUILD_DIR)/LoadGameMenu.o: src/Menus/LoadGameMenu.cpp src/Menus/LoadGameMenu.h src/Menus/Menu.h \
 src/UI/Interface.h src/UI/ITerminal.h src/Commands src/Commands \
 src/Commands src/Commands src/Game.h \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h \
 src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/SaveManager.h src/Players/OnlinePlayer.h
$(BUILD_DIR)/LocalPlayer.o: src/Players/LocalPlayer.cpp src/Players/LocalPlayer.h src/Players/Player.h \
 src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/MainMenu.o: src/Menus/MainMenu.cpp src/Menus/MainMenu.h src/Menus/Menu.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Commands src/Commands src/Game.h \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h \
 src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/Commands src/SaveManager.h \
 src/Menus/StartGameMenu.h src/Commands src/Menus/ChessSetupMenu.h \
 src/Commands src/Commands src/Commands \
 src/Menus/LoadGameMenu.h src/Commands src/Players/OnlinePlayer.h src/Commands
$(BUILD_DIR)/MenuLoadOptionCmd.o: src/Commands src/Commands \
 src/Commands src/UI/Interface.h src/UI/ITerminal.h src/Menus/LoadGameMenu.h \
 src/Menus/Menu.h src/Commands src/Commands src/Commands \
 src/Game.h src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility \
 src/Utility/coordinates.h src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h \
 src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h \
 src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/SaveManager.h \
 src/Players/OnlinePlayer.h
$(BUILD_DIR)/MenuStartOptionCmd.o: src/Commands src/Commands \
 src/Commands src/UI/Interface.h src/UI/ITerminal.h src/Game.h \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h \
 src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h src/Players/Player.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/Commands src/SaveManager.h \
 src/Menus/StartGameMenu.h src/Menus/Menu.h src/Commands src/Menus/ChessSetupMenu.h \
 src/Commands src/Commands
$(BUILD_DIR)/OnlinePlayer.o: src/Players/OnlinePlayer.cpp src/Players/OnlinePlayer.h src/Players/Player.h \
 src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/Pawn.o: src/Pieces/Pawn.cpp src/Pieces/Pawn.h src/Pieces/Piece.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Utility/coordinates.h
$(BUILD_DIR)/Piece.o: src/Pieces/Piece.cpp src/Pieces/Piece.h src/UI/Interface.h src/UI/ITerminal.h \
 src/Utility/coordinates.h
$(BUILD_DIR)/ProgramOptions.o: src/ProgramOptions.cpp src/ProgramOptions.h \
 src/UI/Interface.h src/UI/ITerminal.h
$(BUILD_DIR)/Queen.o: src/Pieces/Queen.cpp src/Pieces/Queen.h src/Pieces/Piece.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Utility/coordinates.h
$(BUILD_DIR)/Rook.o: src/Pieces/Rook.cpp src/Pieces/Rook.h src/Pieces/Piece.h src/UI/Interface.h \
 src/UI/ITerminal.h src/Utility/coordinates.h
$(BUILD_DIR)/SaveGameCmd.o: src/Commands
$(BUILD_DIR)/SaveManager.o: src/SaveManager.cpp src/SaveManager.h
$(BUILD_DIR)/SetupGameCmd.o: src/Commands src/Commands src/Commands \
 src/UI/Interface.h src/UI/ITerminal.h src/Boards/ClassicalChessBoard.h src/Boards/Board.h \
 src/Utility src/Utility/coordinates.h src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h \
 src/Pieces/Queen.h src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Game.h \
 src/Players/LocalPlayer.h src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/Commands src/SaveManager.h src/Menus/ChessSetupMenu.h src/Menus/Menu.h \
 src/Commands
$(BUILD_DIR)/StartGameMenu.o: src/Menus/StartGameMenu.cpp src/Menus/StartGameMenu.h src/Menus/Menu.h \
 src/UI/Interface.h src/UI/ITerminal.h src/Commands src/Commands \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility src/Utility/coordinates.h \
 src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h src/Pieces/Bishop.h \
 src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Game.h src/Players/LocalPlayer.h \
 src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/Commands \
 src/SaveManager.h src/Menus/ChessSetupMenu.h src/Commands \
 src/Commands
$(BUILD_DIR)/main.o: src/main.cpp src/Application.h src/UI/Interface.h src/Menus/MainMenu.h \
 src/Menus/Menu.h src/UI/ITerminal.h src/Commands src/Commands \
 src/Game.h src/Boards/ClassicalChessBoard.h src/Boards/Board.h src/Utility \
 src/Utility/coordinates.h src/Utility/moveTypes.h src/Pieces/Piece.h src/Pieces/King.h src/Pieces/Queen.h \
 src/Pieces/Bishop.h src/Pieces/Knight.h src/Pieces/Rook.h src/Pieces/Pawn.h src/Players/LocalPlayer.h \
 src/Players/Player.h src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h src/Commands \
 src/SaveManager.h src/Menus/StartGameMenu.h src/Commands \
 src/Menus/ChessSetupMenu.h src/Commands src/Commands \
 src/Commands src/Menus/LoadGameMenu.h src/Commands \
 src/Players/OnlinePlayer.h src/Commands src/ProgramOptions.h
