#include "GameBoard.h"
#include "IBattleshipGameAlgo.h"
#include "BoardUtils.h"
#include <iostream>
#define PADDING 2
#define EMPTY_CELL ' '

vector<vector<string>> GameBoard::board() const
{
	return _board;
}

GameBoard::GameBoard(int rows, int cols, int depth)
{
	_rows = rows;
	_cols = cols;
	_depth = depth;
	_board = BoardUtils::getNewEmptyBoard(depth + PADDING, rows + PADDING, cols + PADDING);

}

// expect getting a board with padding
GameBoard::GameBoard(vector<vector<string>>& board, int rows, int cols, int depth, int shipsPerPlayer[])
{
	_depth = depth;
	_rows = rows;
	_cols = cols;
	// get a copy of given board 
	_board = board;
	_shipsPerPlayer = { shipsPerPlayer[0] , shipsPerPlayer[1] };
}

GameBoard::GameBoard(const GameBoard& that)
{
	_depth = that.depth();
	_rows = that.rows();
	_cols = that.cols();
	_board = that.board();
	_shipsPerPlayer = that._shipsPerPlayer;
}

char GameBoard::charAt(Coordinate c) const
{
	if (c.row > _rows || c.col > _cols || c.depth > _depth 
		|| c.row < 0 || c.col < 0 || c.depth < 0)
	{
		return ' '; // As instructed, return ' ' on any invalid coordinate c
	}
	return _board[c.row][c.col][c.depth];
}

void GameBoard::print(bool includePadding) const
{
	BoardUtils::printBoard(_board, includePadding);
}
