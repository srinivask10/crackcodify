#include <iostream>
using namespace std;

#define ROW 5
#define COL 5


int main()
{

    int r = ROW, c = COL, n = ROW;
    int i, j;

    /*
        Solid Rectangle: 
        ****
        ****
        ****
        ****
        ****    
    */    
    cout << "Solid Rectangle: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;

    /*
        Hollow Rectangle: 
        ****
        *  *
        *  *
        *  *
        ****
    */    
    cout << "Hollow Rectangle: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= c; j++)
        {
            if (i == 1 || i == r || j == 1 || j == c)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Half Pyramid: 
        *
        **
        ***
        ****
        *****
    */    
    cout << "Half Pyramid: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;

    /*
        Inverted Half Pyramid: 
        *****
        ****
        ***
        **
        *
    */    
    cout << "Inverted Half Pyramid: " << endl;
    for (i = r; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;

    /*
        Half Pyramid after 180 degree rotation: 
            *
           **
          ***
         ****
        *****
    */    
    cout << "Half Pyramid after 180 degree rotation: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = r-i; j >= 1; j--)
        {
            cout << " ";
        }
        for (j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Half Pyramid using numbers: 
        1
        1 2
        1 2 3
        1 2 3 4
        1 2 3 4 5
    */    
    cout << "Half Pyramid using numbers: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Inverted Half Pyramid using numbers: 
        1 2 3 4 5
        1 2 3 4
        1 2 3
        1 2
        1
    */    
    cout << "Inverted Half Pyramid using numbers: " << endl;
    for (i = r; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    /*
        Half Pyramid using numbers - 2: 
        1
        2 2
        3 3 3
        4 4 4 4
        5 5 5 5 5
    */    
    cout << "Half Pyramid using numbers - 2: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Inverted Half Pyramid using numbers - 2: 
        5 5 5 5 5
        4 4 4 4
        3 3 3
        2 2
        1
    */    
    cout << "Inverted Half Pyramid using numbers - 2: " << endl;
    for (i = r; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Print Floyd's Triangle: 
        1
        2 3
        4 5 6
        7 8 9 10
        11 12 13 14 15
    */    
    int fnum = 1;
    cout << "Floyd's Triangle: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << fnum++ << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        0-1 Pattern: 
        1
        0 1
        1 0 1
        0 1 0 1
        1 0 1 0 1
    */    
    cout << "0-1 Pattern: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if ((i+j)%2 == 0)
                cout << "1 ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Palindromic Pattern: 
                1
              2 1 2
            3 2 1 2 3
          4 3 2 1 2 3 4
        5 4 3 2 1 2 3 4 5
    */    
    cout << "Palindromic Pattern: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= r-i; j++)
            cout << "  ";
        for (j = i; j >= 1; j--)
            cout << j << " ";
        for (j = 2; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
    cout << endl << endl;


    /*
        Diamond using stars: 
            *
           ***
          *****
         *******
        *********
        *********
         *******
          *****
           ***
            *
    */    
    cout << "Diamond using stars: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = i; j <= r; j++)
            cout << " ";
        for (j = 1; j <= (i*2)-1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (i = r; i >= 1; i--)
    {
        for (j = i; j <= r; j++)
            cout << " ";
        for (j = 1; j <= (i*2)-1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << endl << endl;



    /*
        Hollow Diamond using stars: 
            *
           * *
          *   *
         *     *
        *       *
        *       *
         *     *
          *   *
           * *
            *
    */    
    cout << "Diamond using stars: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = i; j <= r; j++)
            cout << " ";
        for (j = 1; j <= (i*2)-1; j++)
        {
            if (j == 1 || j == (i*2)-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (i = r; i >= 1; i--)
    {
        for (j = i; j <= r; j++)
            cout << " ";
        for (j = 1; j <= (i*2)-1; j++)
        {
            if (j == 1 || j == (i*2)-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Hollow Diamond inscribed in rectangle: 
        *********
        **** ****
        ***   ***
        **     **
        *       *
        *       *
        **     **
        ***   ***
        **** ****
        *********
    */    
    cout << "Hollow Diamond inscribed in rectangle: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= (n*2)-1; j++)
        {
            if (j <= (n-i)+1 || j >= (n*2)-(n-i)-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (i = n; i >= 1; i--)
    {
        for (j = 1; j <= (n*2)-1; j++)
        {
            if (j <= (n-i)+1 || j >= (n*2)-(n-i)-1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    /*
        Solid Rhombus: 
            *****
           *****
          *****
         *****
        *****
    */    
    cout << "Solid Rhombus: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= r-i; j++)
            cout << " ";
        for (j = 1; j <= c; j++)
            cout << "*";
        cout << endl;
    }
    cout << endl << endl;


    /*
        Hollow Rhombus: 
            *****
           *   *
          *   *
         *   *
        *****
    */    
    cout << "Hollow Rhombus: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= r-i; j++)
            cout << " ";
        for (j = 1; j <= c; j++)
        {
            if (i == 1 || i == r || j == 1 || j == r)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Pyramid pattern for numbers: 
            1
           2 2 
          3 3 3
         4 4 4 4
        5 5 5 5 5
    */
    cout << "Pyramid pattern for numbers: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= r-i; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
            cout << i << " ";
        cout << endl;
    }
    cout << endl << endl;


    /*
        Pyramid pattern for numbers - 2: 
            1
           1 2
          1 2 3
         1 2 3 4
        1 2 3 4 5
    */
    cout << "Pyramid pattern for numbers - 2: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= r-i; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
            cout << j << " ";
        cout << endl;
    }
    cout << endl << endl;

    /*
        Solid butterfly pattern: 
        *        *
        **      **
        ***    ***
        ****  ****
        **********
        **********
        ****  ****
        ***    ***
        **      **
        *        *
    */
    cout << "Solid butterfly pattern: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
            cout << "*";
        for (j = 1; j <= (r-i)*2; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
    for (i = r; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
            cout << "*";
        for (j = 1; j <= (r-i)*2; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
            cout << "*";
        cout << endl;
    }
    cout << endl << endl;

    /*
        Hollow butterfly pattern: 
            *        *
            **      **
            * *    * *
            *  *  *  *
            *   **   *
            *   **   *
            *  *  *  *
            * *    * *
            **      **
            *        *
    */
    cout << "Hollow butterfly pattern: " << endl;
    for (i = 1; i <= r; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }
        for (j = 1; j <= (r-i)*2; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    for (i = r; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }
        for (j = 1; j <= (r-i)*2; j++)
            cout << " ";
        for (j = 1; j <= i; j++)
        {
            if (j == 1 || j == i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;


    /*
        Zig-Zag Pattern: 
          *   *
         * * * *
        *   *   *
    */
    cout << "Zig-Zag Pattern: " << endl;
    for (i = 1; i <= 3; i++)
    {
        for (j = 1; j <= 20; j++)
        {
            if ((i+j) % 4 == 0 || (i == 2 && j%4 == 0))
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl << endl;

    //TODO: __UNDERSTAND__ : Read about binomial coefficient.
    /*
        Pascal's Triangle: 
            1
           1 1
          1 2 1
         1 3 3 1
        1 4 5 4 1
    */
    cout << "Pascal's Triangle: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n-i; j++)
            cout << " ";
        int C = 1;
        for (j = 1; j <= i; j++)
        {
            cout<< C<<" ";
            C = C * (i - j) / j;
        }
        cout << endl;
    }
    cout << endl << endl;


    return 0;
}
