#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int r) {

    int row_size = matrix.size();
    int col_size = matrix[0].size();
    int rings_num= row_size<=col_size?(row_size/2):(col_size/2);
    int temp1,temp2,temp3;
    int row = row_size - 1;
    int col = col_size - 1;

    for (int k = 0; k < r; k++)
    {
        for (int n = 0; n < rings_num; n++)
        {
            int r1 = n;
            temp1 = matrix[n][n];
            for (int j = n; j < col - n; j++)
                matrix[r1][j] = matrix[r1][j + 1];

            int c1 = n;
            temp2 = matrix[row - n][c1];
            for (int i = row - n; i > r1 + 1; i--)
                matrix[i][c1] = matrix[i - 1][c1];
            matrix[r1 + 1][c1] = temp1;

            int r2 = row - n;
            temp3 = matrix[r2][col - n];
            for (int j = col - n; j > c1 + 1; j--)
                matrix[r2][j] = matrix[r2][j - 1];
            matrix[r2][c1 + 1] = temp2;

            int c2 = col - n;
            for (int i = n; i < r2 - 1; i++)
                matrix[i][c2] = matrix[i + 1][c2];
            matrix[r2 - 1][c2] = temp3;
        }
    }

    for(int i=0;i<row_size;i++)
    {
        for(int j=0;j<col_size;j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
