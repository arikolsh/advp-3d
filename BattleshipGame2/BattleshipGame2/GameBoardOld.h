#pragma once
#include <vector>
#include <map>
#include <memory>
#include "Ship.h"
#include "IBattleshipGameAlgo.h"
using namespace std;
class GameBoardOld {
public:
	GameBoardOld(int rows, int cols);
	~GameBoardOld();
	/*
	 * get the board from path, check validity and fill _fullBoard.
	 * return -1 if unsuccessful and 0 otherwise.
	 */
	int init(string path);
	/* get full board including padding */
	vector<string> getFullBoard() const;
	char** getPlayerBoard(int player) const;
	/* get number of number of rows with padding if true or without if false */
	int getRows(bool padding) const;
	/* get number of number columns with padding if true or without if false */
	int getCols(bool padding) const;
	static void destroyBoard(char ** board, int rows);
	/* print the gameboard. without the padding*/
	void printGameBoard();
private:
	/* number of rows with additional padding */
	int _rows;
	/* number of rows with additional padding */
	int _cols;
	/* The full board for gui purposes*/
	vector<string> _fullBoard;
	/* The game board is implemented using a private map.
	* Each map entry holds a board coordinate (like a matrix cell) as key,
	* and a ship object as value. Since each ship can take a few cells,
	* different keys may hold the same ship object. */
	map<pair<int, int>, pair<shared_ptr<Ship>, bool> > _shipsMap;
	/*disable copy ctor*/
	GameBoardOld(const GameBoardOld& that) = delete;
	/* fill board with data from board file in path. */
	int fillBoardFromFile(string path);
	/* check if board is valid and return 0 if so. return -1 if invalid and
	* print proper messages. */
	int validateBoard();
	/* remove ships with wrong shape or size from board. returns -1 if there are
	* invalid ships and prints proper messages. */
	bool markInvalidShips(vector<string> boardCpy);
	/* Allocates a rows x cols board filled with the symbol c for the use of getPlayerBoard function*/
	static char** GameBoardOld::initBoard(int rows, int cols, char c);
};

