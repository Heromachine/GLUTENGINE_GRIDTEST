#ifndef CLASS_DFSMISSILE_H
#define CLASS_DFSMISSILE_H
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <time.h>  
#include <queue>
#include <stack>

#include "cBaseNode.h"
#include "cGrid.h"


class DFSMissile : public BaseNode
{
private:

	vector<int> moves;

	bool isFinished = false;
	bool isIdle = false;
	bool timeToMove = false;

	int iStartID;
	int iEndID;
	int gridSize;
	int stepsTaken = 0;
	int tilesFound = 0;


public:
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DFSMissile()
	{
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	DFSMissile(Grid &grid, unsigned int StartID, unsigned int EndID)
	{
		iStartID = StartID;
		iEndID = EndID;
		if (grid.getTileValue(StartID) == '|' || grid.getTileValue(EndID) == '|')
		{
			cerr << "THIS TILE IS IN ACCESSABLE";
		}
		else
		{
			grid.setTileValue(StartID, '~');
			grid.setTileValue(EndID, '#');
			this->setPosX(grid.getTilePosX(StartID));
			this->setPosY(grid.getTilePosY(StartID));
			this->setPosZ(grid.getTilePosX(StartID));
			this->gridSize = grid.getCol();

			DFS(grid, StartID, StartID);
			cout << "\nDFS STEPS TAKEN: " << stepsTaken << endl;
		}


	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	void DFS(Grid &grid, int previousstate, int currentState)
	{
		++stepsTaken;
		//cout << "Steps: "<<stepsTaken << endl;
		//cout << "State: " << currentState << endl <<endl; 
		grid.incrimentTileTimesVisited(currentState);
		if (grid.getTileValue(currentState) != '#')
		{
			if (grid.getTileValue(currentState) == 'x')
			{
				grid.setTileValue(currentState, '-');
			}
			else
			if (grid.getTileValue(currentState) == 'o')
			{
				grid.setTileValue(currentState, '-');
			}

			grid.setTileVisited(currentState, true);

			int nextMove = 0;

			if (grid.isTileNeighborsFound(currentState) == false)
			{
				nextMove = getNeighbors(grid, currentState);
				moves.push_back(nextMove);
				grid.setTileNeigborsFound(currentState, true);
			}
			if (nextMove != currentState)
			{
				DFS(grid, currentState, nextMove);
			}
			else
			{
				grid.setTileValue(currentState, '#');
			}
		
		}

	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	int getNeighbors3(Grid &grid, int currentState)
	{//DFS

		int notVisitedPoints = 1;
		int vistedPoints = 1;
		if (grid.isTileVisited(currentState))
		{
			grid.setTilePoints(currentState, grid.getTilePoints(currentState) - 1);
		}
		//else
		//{
		//	grid.setTilePoints(currentState, grid.getTilePoints(currentState) );
		//}

		//grid.consolePrintGrid();
		vector<int> ids;
		ids.push_back(currentState);
		vector<float> Distances;
		Distances.push_back(sqrt
		(
			pow((grid.getTilePosX(currentState) - grid.getTilePosX(iEndID)), 2)
			+
			pow((grid.getTilePosY(currentState) - grid.getTilePosY(iEndID)), 2)
		));

		int bestIDMove;

		//CHECK IF CURRENT NODE FAR LEFT/////////////////////////////////////////////////////
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{
			float DISTANCE = 0;
			int left = currentState - 1;
			//CHECK if LEFT NODE IS OBSTICLE
			if (grid.getTileValue(left) != '|')
			{//CHECK IF LEFT NODE IS VISITED
				if (grid.isTileVisited(left) == false)
				{//POINTS FOR NOT BEING VISITED
					grid.setTilePoints(left, grid.getTilePoints(left) + notVisitedPoints);
					//CALCULATE DISTANCE
					DISTANCE = sqrt
					(
						pow((grid.getTilePosX(left) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(left) - grid.getTilePosY(iEndID)), 2)
					);
					//DISTANCE ADDED TO SET OF DISTANCES
					Distances.push_back(DISTANCE);
					//ADD ID AND VISIT TIMES				
					ids.push_back(left);
				}
				else
				{
					grid.setTilePoints(left, grid.getTilePoints(left) - vistedPoints);
				}

			}

		}
		//CHECK IF CURRENT NODE BOTTOM /////////////////////////////////////////////////////
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			float DISTANCE = 0;
			int bottom = currentState + gridSize;
			//CHECK if LEFT NODE IS OBSTICLE
			if (grid.getTileValue(bottom) != '|')
			{//CHECK IF LOWER NODE IS VISITED
				if (grid.isTileVisited(bottom) == false)
				{
					grid.setTilePoints(bottom, grid.getTilePoints(bottom) + notVisitedPoints);
					//CALCULATE DISTANCE
					DISTANCE = sqrt
					(
						pow((grid.getTilePosX(bottom) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(bottom) - grid.getTilePosY(iEndID)), 2)
					);
					//DISTANCE ADDED TO SET OF DISTANCES
					Distances.push_back(DISTANCE);
					//ID ADDED TO SET OF OPTIONS
					ids.push_back(bottom);
				}
				else
				{
					grid.setTilePoints(bottom, grid.getTilePoints(bottom) - vistedPoints);
				}

			}
		}
		//CHECK IF CURRENT NODE FAR RIGHT/////////////////////////////////////////////////////
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{
			float DISTANCE = 0;
			int right = currentState + 1;
			//CHECK if LEFT NODE IS OBSTICLE
			if (grid.getTileValue(right) != '|')
			{//CHECK IF VLEFT NODE IS ISITED				
				if (grid.isTileVisited(right) == false)
				{
					grid.setTilePoints(right, grid.getTilePoints(right) + notVisitedPoints);
					//DISTANCE CALCULATED
					DISTANCE = sqrt
					(
						pow((grid.getTilePosX(right) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(right) - grid.getTilePosY(iEndID)), 2)
					);
					//DISTANCE IS ADDED TO SET OF DISTANCES
					Distances.push_back(DISTANCE);
					//ID ADDED TO SET OF OPTIONS
					ids.push_back(right);
				}
				else
				{
					grid.setTilePoints(right, grid.getTilePoints(right) - vistedPoints);
				}

			}
		}
		//CHECK IF CURRENT NODE TOP/////////////////////////////////////////////////////
		if ((grid.getTileID(currentState) >= gridSize))
		{
			float DISTANCE = 0;
			int top = currentState - gridSize;
			//CHECK if TOP NODE IS OBSTICLE
			if (grid.getTileValue(top) != '|')
			{//CHECK IF UPPER NODE IS VISITED
				if (grid.isTileVisited(top) == false)
				{//POINT FOR NOT BEING VISITED
					grid.setTilePoints(top, grid.getTilePoints(top) + notVisitedPoints);
					DISTANCE = sqrt
					(
						pow((grid.getTilePosX(top) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(top) - grid.getTilePosY(iEndID)), 2)
					);
					//DISTANCE ADDED TO SET OF DISTANCES
					Distances.push_back(DISTANCE);
					//ID ADDED TO SET OF OPTIONS
					ids.push_back(top);
				}
				else
				{
					grid.setTilePoints(top, grid.getTilePoints(top) - vistedPoints);
				}
			}
		}
		/////////////////////////////////////////////////////
		int BestID = currentState;
		cout << endl << currentState << endl;
		int MostPoints = 0;

		for (int i = 0; i < ids.size(); i++)
		{
			grid.setTilePoints(ids.at(i), grid.getTilePoints(ids.at(i)) + 3);
			for (int j = 0; j < ids.size(); j++)
			{
				if (Distances.at(i) < Distances.at(j))
				{
					BestID = ids.at(i);
					grid.setTilePoints(BestID, grid.getTilePoints(BestID) + 1);
				}
				else
				{
					grid.setTilePoints(ids.at(j), grid.getTilePoints(BestID) - 1);
				}
			}
		}

		grid.setTilePoints(BestID, grid.getTilePoints(BestID) - 2);
		
		for (int i = 0; i < ids.size(); i++)
		{
			
			if (grid.getTilePoints(ids.at(i)) >= grid.getTilePoints(BestID))
			{
				cout << " \n\tID: " << ids.at(i) << "| D: " << Distances.at(i) << " |Points: " << grid.getTilePoints(ids.at(i)) << endl;
				BestID = ids.at(i);
			}
		}
		cout << "\nBEST ID:" << BestID << " has " << grid.getTilePoints(BestID) << endl;
		bestIDMove = BestID;

		return bestIDMove;
	}
	int getNeighbors2(Grid &grid, int currentState)
	{//DFS

		int notVisitedPoints = 200;
		int vistedPoints = 2;
		if (grid.isTileVisited(currentState))
		{
			grid.setTilePoints(currentState, grid.getTilePoints(currentState)  - 1);
		}
		//else
		//{
		//	grid.setTilePoints(currentState, grid.getTilePoints(currentState) );
		//}

		
		//grid.consolePrintGrid();
		vector<int> ids;
		vector<float> Distances;

		int bestIDMove;
 
		//CHECK IF CURRENT NODE FAR LEFT
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{
			float DISTANCE = 0;
			int left = currentState - 1;
			//CHECK if LEFT NODE IS OBSTICLE
			if (grid.getTileValue(left) != '|')
			{//CHECK IF LEFT NODE IS VISITED
				if (grid.isTileVisited(left) == false)
				{//POINTS FOR NOT BEING VISITED
					grid.setTilePoints(left, grid.getTilePoints(left) + notVisitedPoints);
				}
				else
				{
					grid.setTilePoints(left, grid.getTilePoints(left) - vistedPoints);
				}
				//CALCULATE DISTANCE
				DISTANCE = sqrt
				(
					pow((grid.getTilePosX(left) - grid.getTilePosX(iEndID)), 2)
					+
					pow((grid.getTilePosY(left) - grid.getTilePosY(iEndID)), 2)
				);
				//DISTANCE ADDED TO SET OF DISTANCES
				Distances.push_back(DISTANCE);
				//ADD ID AND VISIT TIMES				
				ids.push_back(left);
			}

		}
		//CHECK IF CURRENT NODE BOTTOM 
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			float DISTANCE = 0;
			int bottom = currentState + gridSize;
			//CHECK if LEFT NODE IS OBSTICLE
			if (grid.getTileValue(bottom) != '|')
			{//CHECK IF LOWER NODE IS VISITED
				if (grid.isTileVisited(bottom) == false)
				{
					grid.setTilePoints(bottom, grid.getTilePoints(bottom) + notVisitedPoints);
				}
				else
				{
					grid.setTilePoints(bottom, grid.getTilePoints(bottom) - vistedPoints);
				}
				//CALCULATE DISTANCE
				DISTANCE = sqrt
				(
					pow((grid.getTilePosX(bottom) - grid.getTilePosX(iEndID)), 2)
					+
					pow((grid.getTilePosY(bottom) - grid.getTilePosY(iEndID)), 2)
				);
				//DISTANCE ADDED TO SET OF DISTANCES
				Distances.push_back(DISTANCE);
				//ID ADDED TO SET OF OPTIONS
				ids.push_back(bottom);
			}
		}
		//CHECK IF CURRENT NODE FAR RIGHT
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{
			float DISTANCE = 0;
			int right = currentState + 1;
			//CHECK if LEFT NODE IS OBSTICLE
			if (grid.getTileValue(right) != '|' )
			{//CHECK IF VLEFT NODE IS ISITED				
				if (grid.isTileVisited(right) == false)
				{
					grid.setTilePoints(right, grid.getTilePoints(right) + notVisitedPoints);
				}
				else
				{
					grid.setTilePoints(right, grid.getTilePoints(right) - vistedPoints);
				}
				//DISTANCE CALCULATED
				DISTANCE = sqrt
				(
					pow((grid.getTilePosX(right) - grid.getTilePosX(iEndID)), 2)
					+
					pow((grid.getTilePosY(right) - grid.getTilePosY(iEndID)), 2)
				);
				//DISTANCE IS ADDED TO SET OF DISTANCES
				Distances.push_back(DISTANCE);
				//ID ADDED TO SET OF OPTIONS
				ids.push_back(right);
			}
		}
		//CHECK IF CURRENT NODE TOP
		if ((grid.getTileID(currentState) >= gridSize))
		{
			float DISTANCE = 0;
			int top = currentState - gridSize;
			//CHECK if TOP NODE IS OBSTICLE
			if (grid.getTileValue(top) != '|')
			{//CHECK IF UPPER NODE IS VISITED
				if (grid.isTileVisited(top) == false)
				{//POINT FOR NOT BEING VISITED
					grid.setTilePoints(top, grid.getTilePoints(top) + notVisitedPoints);
				}
				else
				{//REMOVE POINT FOR BEING VISITED
					grid.setTilePoints(top, grid.getTilePoints(top) - vistedPoints);
				}					
				DISTANCE = sqrt
				(
					pow((grid.getTilePosX(top) - grid.getTilePosX(iEndID)), 2)
					+
					pow((grid.getTilePosY(top) - grid.getTilePosY(iEndID)), 2)
				);
				//DISTANCE ADDED TO SET OF DISTANCES
				Distances.push_back(DISTANCE);
				//ID ADDED TO SET OF OPTIONS
				ids.push_back(top);
			}
		}

		int BestID = currentState;
		cout << endl << currentState<<endl;
		int MostPoints = 0;

		for (int i = 0; i < ids.size(); i++)
		{

			for (int j = 0; j < ids.size(); j++)
			{
				if (Distances.at(i) < Distances.at(j))
				{
					BestID = ids.at(i);
					grid.setTilePoints(BestID, grid.getTilePoints(BestID) + 1);
				}
			}				
		}
		grid.setTilePoints(BestID, grid.getTilePoints(BestID) + 2);

		for (int i = 0; i < ids.size(); i++)
		{
			if (grid.getTilePoints(ids.at(i)) >= grid.getTilePoints(BestID))
			{
				cout << " \n\tID: " << ids.at(i) << "| D: " << Distances.at(i) << " |Points: " << grid.getTilePoints(ids.at(i)) << endl;
				BestID = ids.at(i);
			}
		}
		cout << "\nBEST ID:" << BestID << " has " << grid.getTilePoints(BestID)<<endl;
		bestIDMove = BestID;
		
		return bestIDMove;
	}
	int getNeighbors(Grid &grid, int currentState)
	{//DFS
		vector<int> ids;
		vector<int> Points;

		ids.push_back(currentState);
		Points.push_back(grid.getTilePoints(currentState));

		float DISTANCE = sqrt
		(
			pow((grid.getTilePosX(currentState) - grid.getTilePosX(iEndID)), 2)
			+
			pow((grid.getTilePosY(currentState) - grid.getTilePosY(iEndID)), 2)
		);
		float BESTDISATNCE = DISTANCE;
		int bestMove = currentState;
		//CHECK IF CURRENT NODE FAR LEFT
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{
			//CHECK if LEFT NODE IS OBSTICLE
			if (
				grid.getTileValue(currentState - 1) != '|' &&
				grid.getTileValue(currentState - 1) != '-'
				)
			{
				//ADD ID AND VISIT TIMES
				ids.push_back(currentState - 1);
				Points.push_back(grid.getTilePoints(currentState - 1));

				//CHECK IF LEFT NODE IS VISITED
				if (grid.isTileVisited(currentState - 1) == false)
				{
					float DISTANCE = sqrt
					(
						pow((grid.getTilePosX(currentState - 1) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(currentState - 1) - grid.getTilePosY(iEndID)), 2)
					);

					BESTDISATNCE = DISTANCE;
					bestMove = currentState - 1;
				}
			}

		}
		//CHECK IF CURRENT NODE BOTTOM 
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			//CHECK if LEFT NODE IS OBSTICLE
			if (
				grid.getTileValue(currentState + gridSize) != '|' &&
				grid.getTileValue(currentState + gridSize) != '-'
				)
			{
				ids.push_back(currentState + gridSize);
				Points.push_back(grid.getTilePoints(currentState + gridSize));

				//CHECK IF LOWER NODE IS VISITED
				if (grid.isTileVisited((currentState + gridSize) == false))
				{

					float DISTANCE = sqrt
					(
						pow((grid.getTilePosX(currentState + gridSize) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(currentState + gridSize) - grid.getTilePosY(iEndID)), 2)
					);

					if (BESTDISATNCE > DISTANCE)
					{
						BESTDISATNCE = DISTANCE;
						bestMove = currentState + gridSize;
					}
				}
			}
		}
		//CHECK IF CURRENT NODE FAR RIGHT
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{

			//CHECK if LEFT NODE IS OBSTICLE
			if (
				grid.getTileValue(currentState + 1) != '|' &&
				grid.getTileValue(currentState + 1) != '-'
				)
			{
				ids.push_back(currentState + 1);
				Points.push_back(grid.getTilePoints(currentState + 1));
				//CHECK IF RIGHT NODE IS VISITED
				if (grid.isTileVisited(currentState + 1) == false)
				{
					float DISTANCE = sqrt
					(
						pow((grid.getTilePosX(currentState + 1) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(currentState + 1) - grid.getTilePosY(iEndID)), 2)
					);
					if (BESTDISATNCE > DISTANCE)
					{
						BESTDISATNCE = DISTANCE;
						bestMove = currentState + 1;
					}
				}
			}
		}
		//CHECK IF CURRENT NODE TOP
		if ((grid.getTileID(currentState) >= gridSize))
		{
			//CHECK if LEFT NODE IS OBSTICLE
			if (
				grid.getTileValue(currentState - gridSize) != '|' &&
				grid.getTileValue(currentState - gridSize) != '-'
				)
			{
				ids.push_back(currentState - gridSize);
				Points.push_back(grid.getTilePoints(currentState - gridSize));
				//CHECK IF UPPER NODE IS VISITED
				if (grid.isTileVisited(currentState - gridSize) == false)
				{
					float DISTANCE = sqrt
					(
						pow((grid.getTilePosX(currentState - gridSize) - grid.getTilePosX(iEndID)), 2)
						+
						pow((grid.getTilePosY(currentState - gridSize) - grid.getTilePosY(iEndID)), 2)
					);
					if (BESTDISATNCE > DISTANCE)
					{
						BESTDISATNCE = DISTANCE;
						bestMove = currentState - gridSize;
					}
				}
			}
		}
		if (bestMove == currentState)
		{
			int BestID = currentState;
			int BestTimeVisited = grid.getTilePoints(currentState);

			for (int i = 1; i < ids.size(); i++)
			{
				if (grid.getTilePoints(ids.at(i)) < grid.getTilePoints(BestID))
				{
					BestID = ids.at(i);
				}
			}
			bestMove = BestID;
		}
		return bestMove;
	}
	void TravelBestPath(Grid &grid, bool canmove)
	{
		if (canmove)
		{
			this->setPosX(grid.getTilePosX(moves.front()));
			moves.erase(moves.begin());
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////

};
#endif // !CLASS_VACCUM_H///////////////////////////////////////////////////////////////////////////////////////////////////////////END

