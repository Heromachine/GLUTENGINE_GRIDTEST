#ifndef A_STAR_MISSLE_H
#define A_STAR_MISSLE_H
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <time.h>  
#include <queue>
#include <stack>

#include "cBaseNode.h"
#include "cGrid.h"

class AStartMissile : public BaseNode
{
private:



	vector<int> moves;
	stack<int> PathNodes;

	float explosionRadius = 4;
	
	bool bIsDetonated = false;
	bool timeToMove = false;

	int iStartID;
	int iEndID;
	int gridSize;
	int stepsTaken = 0;
	int tilesFound = 0;

	time_t start = time(0);
	time_t end = 0;

	float moveTime = 0.05f;


	

public:
	AStartMissile() {}
	AStartMissile(Grid &grid, unsigned int StartID, unsigned int EndID)
	{

		iStartID = StartID;
		iEndID = EndID;
		grid.setTIleParentNode(StartID, StartID);

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
			AStarSearch(grid, StartID, StartID);
			cout << "\nA* SEARCH STEPS TAKEN: "<< stepsTaken<<endl;

		}
	}


	void blowUp(ManagerAsteroid &MA, int &Money)
	{
		for (int i = 0; i < MA.getClusterSize(); i++)
		{
			float Distance = CalDistance(this->getPosX(), this->getPosY(), MA.getAsteroidPosX(i), MA.getAsteroidPosY(i));
			if (Distance < explosionRadius)
			{
				MA.eraseAsteroid(i);
			}
		}	
	}
	void updateMisslePath(Grid &grid, ManagerAsteroid &MA, int &Money)
	{

		if (PathNodes.empty())
		{
			if (bIsDetonated)
				blowUp(MA, Money);
		}
		else
		{
			if (end - start > moveTime)
			{
				this->setPosX(grid.getTilePosX(PathNodes.top()));
				this->setPosY(grid.getTilePosY(PathNodes.top()));
				PathNodes.pop();
				start = time(0);

			}
			else
			{
				end = time(0);
			}
		}
	}
	void CalshootMissile(Grid &grid, SpaceShip &ship, ManagerAsteroid &MA)
	{	
		markAstroidLoc(grid, MA);
		markShipLoc(grid, ship);
		AStarSearch(grid, this->iStartID, this->iEndID);
		getPath(grid, this->iEndID);
	}

	void getPath(Grid &grid, int currentID)
	{
		if (currentID != this->iStartID)
		{
			PathNodes.push(grid.getTileParentNode(currentID));
			getPath(grid, grid.getTileParentNode(currentID));
		}
		else
		{
			bIsDetonated = true;
		}

		
		for (int i = 0; i < PathNodes.size(); i++)
		{
			cout << PathNodes.top();
			PathNodes.pop();
		}
	
	}
	void markShipLoc( Grid &grid, SpaceShip &ship)
	{
		int ClosestTile = 0;
		float ClosesDistance = 10000;
		for (int g = 0; g < gridSize * gridSize; g++)
		{			
			float CurrentDistance = CalDistance(grid.getTilePosX(g), grid.getTilePosY(g), ship.getPosX(), ship.getPosY());
			if (CurrentDistance < ClosesDistance)
			{
				ClosesDistance = CurrentDistance;
				ClosestTile = g;
				
			}
		}

		iStartID = ClosestTile;
		this->setPosX(grid.getTilePosX(ClosestTile));
		this->setPosX(grid.getTilePosX(ClosestTile));
		
	}

	void markAstroidLoc(Grid &grid,  ManagerAsteroid &MA)
	{
		float Closest = CalDistance(grid.getTilePosX(0), grid.getTilePosY(0), MA.GetAsteroid(0).getPosX(), MA.GetAsteroid(0).getPosY());
		int ClosestT= 0;
		for (int a = 0; a < MA.getClusterSize(); a++)
		{			
			for (int g = 0; g < gridSize * gridSize; g++)
			{
				float pos = CalDistance(grid.getTilePosX(g), grid.getTilePosY(g), MA.GetAsteroid(a).getPosX(), MA.GetAsteroid(a).getPosY());
				if (pos < Closest)
				{
					Closest = pos;
					ClosestT = g;
					grid.setTileValue(ClosestT, '|');
				}
				
			}
		}
	}

	void AStarSearch(Grid &grid, int previousstate, int currentState)
	{

		++stepsTaken;

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

			vector <int> nextMoves;

			if (grid.isTileNeighborsFound(currentState) == false)
			{
				nextMoves = getNeighbors(grid, previousstate, currentState);
				grid.setTileNeigborsFound(currentState, true);
			}
			for (int i = 0; i < nextMoves.size(); i++)
			{
				
				AStarSearch(grid, currentState, nextMoves.at(i));

			}
		}
	}

	vector<int> getNeighbors(Grid &grid, int previousState, int currentState)
	{
		vector<int> seen;
		int left = 0;
		int right = 0;
		int top = 0;
		int bottom = 0;

		//CHECK IF CURRENT NODE FAR LEFT/////////////////////////////////////////////////////
		if (!(grid.getTileID(currentState) % gridSize == 0))
		{

			left = currentState - 1;
			if (grid.getTileValue(left) != '|')
				if (!grid.isTileVisited(left))
				{
					grid.setTIleParentNode(left, currentState);
					//CALCULATE COSTS; 
					CalculateCosts(grid, left);
					seen.push_back(left);
				}
		}
		//CHECK IF CURRENT NODE FAR RIGHT/////////////////////////////////////////////////////
		if (!(grid.getTileID(currentState) % gridSize == gridSize - 1))
		{
			right = currentState + 1;
			if (grid.getTileValue(right) != '|')
				if (!grid.isTileVisited(right))
				{
					grid.setTIleParentNode(right, currentState);
					//CALCULATE COSTS; 
					CalculateCosts(grid, right);
					seen.push_back(right);
				}
		}
		//CHECK IF CURRENT NODE TOP/////////////////////////////////////////////////////
		if ((grid.getTileID(currentState) >= gridSize))
		{
			top = currentState - gridSize;
			if (grid.getTileValue(top) != '|')
				if (!grid.isTileVisited(top))
				{
					grid.setTIleParentNode(top, currentState);
					//CALCULATE COSTS; 
					CalculateCosts(grid, top);
					seen.push_back(top);
				}
		}
		//CHECK IF CURRENT NODE BOTTOM /////////////////////////////////////////////////////
		if (grid.getTileID(currentState) < (gridSize * gridSize) - gridSize)
		{
			bottom = currentState + gridSize;
			if (grid.getTileValue(bottom) != '|')
				if (!grid.isTileVisited(bottom))
				{
					grid.setTIleParentNode(bottom, currentState);
					//CALCULATE COSTS; 
					CalculateCosts(grid, bottom);
					seen.push_back(bottom);
				}
		}


		vector <int> BestNodes = seen;

		//CHECK FOR BEST F COST FIRST OR H COST IF F COST THE SAME
		for (int i = 0; i < BestNodes.size(); i++)
		{
			if (grid.getTileValue(BestNodes.at(i))!= '#')
			grid.setTileValue(BestNodes.at(i), 'o');
			for (int j = 0; j < BestNodes.size(); j++)
			{
				if (BestNodes.at(i) != BestNodes.at(j))	//IF THE FCOST IS GREATER THAN THE OTHER NODES 
					if (grid.getTileFCost(BestNodes.at(i)) > grid.getTileFCost(BestNodes.at(j)))
					{//DELETE THE NODE
						BestNodes.erase(BestNodes.begin() + i);
					}
					else //IF THE HCOST IS THE SAME CHECK
						if (grid.getTileHCost(BestNodes.at(i)) == grid.getTileHCost(BestNodes.at(j)))
						{
							for (int i = 0; i < BestNodes.size(); i++)
							{
								for (int j = 0; j < BestNodes.size(); j++)
								{
									if (BestNodes.at(i) != BestNodes.at(j)) //IF THE HCOST IS THE GREATER
										if (grid.getTileHCost(BestNodes.at(i)) < grid.getTileHCost(BestNodes.at(j)))
										{//DELETE THE NODE
											BestNodes.erase(BestNodes.begin() + i);
										}
								}
							}
						}
			}
		}
		return BestNodes;

	}

	float CalDistance(float x1, float y1, float x2, float y2)
	{
		return  sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));	
	}

	void CalculateCosts(Grid &grid, int idCurrent)
	{
		//CALCULATE HCOST
		float HDistance = 0;
		HDistance = sqrt
		(
			pow((grid.getTilePosX(idCurrent) - grid.getTilePosX(iEndID)), 2)
			+
			pow((grid.getTilePosY(idCurrent) - grid.getTilePosY(iEndID)), 2)
		);
		grid.setTileHCost(idCurrent, HDistance);

		//CALCULATE GCOST
		float GDistance = 0;
		GDistance = sqrt
		(
			pow((grid.getTilePosX(idCurrent) - grid.getTilePosX(iStartID)), 2)
			+
			pow((grid.getTilePosY(idCurrent) - grid.getTilePosY(iStartID)), 2)
		);
		grid.setTileGCost(idCurrent, GDistance);

		//CALCULATE FCOST
		grid.setTileFCost(idCurrent, GDistance + HDistance);

		if (//GET THE GCOST OF CURRENT'S PARENT PARENT NODE 
			grid.getTileGCost(grid.getTileParentNode(grid.getTileParentNode(idCurrent)))
			<//IF PARENT PARENT NODE LESS
			grid.getTileGCost(grid.getTileParentNode(idCurrent)) //PARENT NODE GCOST
			)
		{
			//CURRENT NODE PARENT = PARRENT PARENT
			grid.setTIleParentNode(idCurrent, grid.getTileParentNode(grid.getTileParentNode(idCurrent)));
		}
	}

	bool isDetonated()
	{
		return this->bIsDetonated;
	}

};







#endif // !A_STAR_MISSLE_H

