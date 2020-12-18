#include<bits/stdc++.h>
using namespace std;




int main()
{


#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    char M[n][n];
    char ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == 'C')
                M[i][j] = '0';
            else
                M[i][j] = '1';
        }
    }


    int i, j;
    int R = n;
    int C = n;
    int S[R][C];
    int max_of_s, max_i, max_j;

    /* Set first column of S[][]*/
    for (i = 0; i < R; i++)
        S[i][0] = M[i][0];

    /* Set first row of S[][]*/
    for (j = 0; j < C; j++)
        S[0][j] = M[0][j];

    /* Construct other entries of S[][]*/
    for (i = 1; i < R; i++)
    {
        for (j = 1; j < C; j++)
        {
            if (M[i][j] == 1)
                S[i][j] = min(S[i][j - 1], min( S[i - 1][j],
                                                S[i - 1][j - 1])) + 1;
            else
                S[i][j] = 0;
        }
    }

    /* Find the maximum entry, and indexes of maximum entry
        in S[][] */
    max_of_s = S[0][0]; max_i = 0; max_j = 0;
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            if (max_of_s < S[i][j])
            {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << "Maximum size sub-matrix is: \n";
    for (i = max_i; i > max_i - max_of_s; i--)
    {
        for (j = max_j; j > max_j - max_of_s; j--)
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }




}

