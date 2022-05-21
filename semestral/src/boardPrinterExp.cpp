
#include <filesystem>
#include <string>
#include <fstream>
//#include <iomanip>
#include <iostream>
//#include <chrono>
#include <map>
#include <vector>
#include <array>

using namespace std;

class Piece
{
    public:
        Piece();
        Piece(const char & s, const bool & c) : symbol(s), colour(c), coords(0,0) {}
        /**
         * Displays Piece on the board
         * @param interface
         */
        virtual void Print(ostream & interface)
        {
        
        	string bg = "\e[41m"; 
        	char out = symbol;
    		if(colour)
    		{
				bg = "\e[44m";
        		out = tolower(out);
    		}

    		interface << bg << out << "\e[0m";
        }
        /**
         * glorified print method
         * prints Piece in a format used by SaveManager
         * @param os file to write to
         */
    protected:
        struct coordinates
        {
            coordinates(char h, int v) : horizontal(h), vertical(v){}
            char horizontal;
            int vertical;
        };
        char symbol;
        bool colour; // 0 = white | 1 = black
        coordinates coords;
};


class King : public Piece
{
    public:
        King(const bool & col) : Piece('K',col)
        {}
};


class Queen : public Piece
{
    public:
        Queen(const bool & col) : Piece('Q',col)
        {}
};

class Bishop : public Piece
{
    public:
        Bishop(const bool & col) : Piece('B',col)
        {}
};
class Knight : public Piece
{
    public:
        Knight(const bool & col) : Piece('N',col)
        {}
};
class Rook : public Piece
{
    public:
        Rook(const bool & col) : Piece('R',col)
        {}
};
class Pawn : public Piece
{
    public:
        Pawn(const bool & col) : Piece('P',col)
        {}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

string State(const array<shared_ptr<Piece>, 64> & board)
{
	std::stringstream output;
	output << "   ";
   	for(int i = 0; i < 8; ++i)
    {
    	output << " " << static_cast<char>('A' + i);
        if(i == 7)
        	output << ' ';
    }
    output << '\n';
    output << "  +" << string(17, '-') << '+';
    for(int i = 0; i < 64; ++i)
    {
    	
    	if(i % 8 == 0)
    		output << endl << (i/8) + 1 << " |";
    	if(board[i])
    	{
    		output << ' ';
    		board[i]->Print(output);
    		if(i % 8 == 7)			
    		output << ' ';	
    	}
    	else
    	{
    		output << noskipws << " .";
			if(i % 8 == 7)			
    			output << ' ';    	    	
    	}
    	if(i % 8 == 7)			
    		output << "| " << (i+1) / 8;
    }
    output << '\n';
    output << "  +" << string(17, '-') << '+' << endl << "   ";
    for(int i = 0; i < 8; ++i)
    {
    	//cout << 'A' + i;
        output << ' ' << static_cast<char>('A' + i);
        if(i == 7)
        	output << ' ';
    }
    output << ' ' <<'\n';
    return output.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    array<shared_ptr<Piece>, 64> board;
#define white true
#define black false
    board[0] = std::make_shared<Rook>(white);
    board[1] = std::make_shared<Knight>(white);
    board[2] = std::make_shared<Bishop>(white);
    board[3] = std::make_shared<King>(white);
    board[4] = std::make_shared<Queen>(white);
    board[5] = std::make_shared<Bishop>(white);
    board[6] = std::make_shared<Knight>(white);
    board[7] = std::make_shared<Rook>(white);
    for(int i = 8; i < 16; ++i)
    {
        board[i] = std::make_shared<Pawn>(white);
    }
    for(int i = 16; i < 48; ++i)
    {
        board[i] = nullptr;
    }
    for(int i = 48; i < 56; ++i)
    {
        board[i] = std::make_shared<Pawn>(black);
    }
    board[56] = std::make_shared<Rook>(black);
    board[57] = std::make_shared<Knight>(black);
    board[58] = std::make_shared<Bishop>(black);
    board[59] = std::make_shared<King>(black);
    board[60] = std::make_shared<Queen>(black);
    board[61] = std::make_shared<Bishop>(black);
    board[62] = std::make_shared<Knight>(black);
    board[63] = std::make_shared<Rook>(black);

    cout << State(board) << endl;	
}
