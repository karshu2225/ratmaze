#include<stdio.h>
#include<conio.h>
#define N 5 //Maze Size 5X5 matrix
char true, false;
//Function declarations
void maze(int m[N][N]);
int maze_soln(int soln[N][N], int m[N][N],int ,int,int path[N][N]);
int issafe(int m[N][N], int x, int y,int path[N][N]);

// This function checks for valid cell. If already visited in the past
// path[][] will take care of returning false.
int issafe(int m[N][N], int x, int y,int path[N][N])
{
    if (x >= 0 && y >= 0 && x < N && y < N && m[x][y] == 1 && path[x][y] !=1)
        return true; // Valid cell.
    else
        return false;
}

// Maze solutions. Checks for proper cell. finds proper path 
// By going LEFT,RIGHT,UP or DOWN
int maze_soln(int soln[N][N], int m[N][N],int x,int y,int path[N][N])
{
    //All the cells have been visited
    if (x == N - 1 && y == N - 1)
    {
        soln[x][y] = 1; //mark the cell as possible path
        return true;
    }

    // Find out different paths
    if (issafe(m, x, y,path) == true)
    {
        soln[x][y] = 1; // mark the cell as possible solution
        path[x][y] = 1; //mark the path as visited

        // Go RIGHT and see if there's a path
        if (maze_soln(soln, m, x, y + 1,path))
            return true;

        //LEFT
        if (y> 0 && maze_soln(soln, m, x, y-1,path))
            return true;

        //DOWN
        if (maze_soln(soln, m, x + 1, y,path))
            return true;

        //UP
        if (x>0 && maze_soln(soln, m, x - 1, y,path))
            return true;

        soln[x][y] = 0;
        return false;
    }
    return false;
}

// Prints the solution matrix if proper path is found
void maze(int m[N][N])
{
    int i, j;
    int soln[N][N] = { 0 };
    int path[N][N] = { 0 };
    if (maze_soln(soln, m, 0, 0,path) == true)
    {
        printf("\n Solution\n"); //Print solution matrix
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                printf("\t%d", soln[i][j]);
            }
            printf("\n");
        }
    }

    return;
}

// Main function
int main()
{
    int i, j;
    //Maze matrix
    int m[N][N] = { { 1,1,1,0,0 },
                    { 1,1,0,1,0 },
                    { 0,1,0,1,1 },
                    { 1,1,1,1,1 },
                    { 1,0,0,1,1 } };

    //Print the Maze
    printf("MAZE\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("\t%d", m[i][j]);
        }
        printf("\n");
    }

    //Call maze function to find out the path
    // and print the solution matrix
    maze(m);
    _getch();
}