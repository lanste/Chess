CXX=g++
CXXFLAGS=-Wall -pedantic -g
LD=g++
LDFLAGS=-pedantic

all: chess

chess: main.o ProgramOptions.o# Application.o Game.o MainMenu.o Board.o ClassicalChessBoard.o Bishop.o King.o Queen.o Knight.o Rook.o Pawn.o \
	Piece.o AI1.o AI2.o AI3.o Player.o LocalPlayer.o OnlinePlayer.o ITerminal.o UIManager.o
	$(LD) $(LDFLAGS) main.o -o chess

clean:
	rm -f chess *.o

%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# here add output of "g++ -MM *.cpp >>Makefile"

Application.o: src/Application/Application.cpp src/Application/Application.h src/UI/Interface.h \
 src/Application src/UI/ITerminal.h src/Application/Game.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/Players/LocalPlayer.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/Application/ProgramOptions.h
Game.o: src/Application/Game.cpp src/Application/Game.h src/UI/Interface.h src/UI/ITerminal.h \
 src/Boards/Board.h src/Boards/../Players/Player.h \
 src/Players/LocalPlayer.h src/Players/AI1.h src/Players/AI2.h \
 src/Players/AI3.h
main.o: src/main.cpp src/Application/Application.h src/UI/Interface.h src/Application \
 src/UI/ITerminal.h src/Application/Game.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/Players/LocalPlayer.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h \
 src/Application/ProgramOptions.h
MainMenu.o: src/Application src/Application src/UI/Interface.h \
 src/UI/ITerminal.h src/Application/Game.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/Players/LocalPlayer.h \
 src/Players/AI1.h src/Players/AI2.h src/Players/AI3.h
ProgramOptions.o: src/Application/ProgramOptions.cpp src/Application/ProgramOptions.h \
 src/UI/Interface.h src/UI/ITerminal.h
Board.o:src/Boards/Board.h \
 src/Boards/../Players/Player.h
ClassicalChessBoard.o: src/Boards/ClassicalChessBoard.cpp \
 src/Boards/ClassicalChessBoard.h src/Boards/Board.h \
 src/Boards/../Players/Player.h src/UI/Interface.h \
 src/Boards/../UI/ITerminal.h src/Boards/../Pieces/Piece.h \
 src/Boards/../Pieces/King.h src/Boards/../Pieces/Queen.h \
 src/Boards/../Pieces/Bishop.h src/Boards/../Pieces/Knight.h \
 src/Boards/../Pieces/Rook.h src/Boards/../Pieces/Pawn.h
Bishop.o: src/Pieces/Bishop.cpp src/Pieces/Bishop.h src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
King.o: src/Pieces/King.cpp src/Pieces/King.h src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
Knight.o: src/Pieces/Knight.cpp src/Pieces/Knight.h src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
Pawn.o: src/Pieces/Pawn.cpp src/Pieces/Pawn.h src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
Piece.o: src/Pieces/Piece.cpp src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
Queen.o: src/Pieces/Queen.cpp src/Pieces/Queen.h src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
Rook.o: src/Pieces/Rook.cpp src/Pieces/Rook.h src/Pieces/Piece.h \
 src/UI/Interface.h src/Pieces/../UI/ITerminal.h
AI1.o: src/Players/AI1.cpp src/Players/AI1.h src/Players/Player.h
AI2.o: src/Players/AI2.cpp src/Players/AI2.h src/Players/Player.h
AI3.o: src/Players/AI3.cpp src/Players/AI3.h src/Players/Player.h
LocalPlayer.o: src/Players/LocalPlayer.cpp src/Players/LocalPlayer.h \
 src/Players/Player.h
OnlinePlayer.o: src/Players/OnlinePlayer.cpp src/Players/OnlinePlayer.h \
 src/Players/Player.h
Player.o: src/Players/Player.cpp src/Players/Player.h
ITerminal.o: src/UI/ITerminal.cpp src/UI/ITerminal.h src/UI/Interface.h
UIManager.o: src/UI/UIManager.cpp src/UI/Interface.h
