
class Solution
{
private:
	void setLeftTopZeros(vector < vector<int>>& m, int row, int col)
	{
		m[row][0] = 0;
		m[0][col] = 0;
	}

	void setRowZeros(vector<vector<int>>&m, int row)
	{
		for (int i = 1; i < m[0].size(); ++i)
		{
			m[row][i] = 0;
		}
	}

	void setColZeros(vector<vector<int>>&m, int col)
	{
		for (int i = 1; i < m.size(); ++i)
		{
			m[i][col] = 0;
		}
	}

public:
	void setZeroes(vector<vector<int>>& matrix)
	{
		if (matrix.size() == 0)
		{
			return;
		}
		bool firstRow = false;
		bool firstCol = false;

		for (int i = 0; i < matrix[0].size(); ++i)
		{
			if (matrix[0][i] == 0)
			{
				firstRow = true;
				break;
			}
		}
		for (int i = 0; i < matrix.size(); ++i)
		{
			if (matrix[i].size() > 0 && matrix[i][0] == 0)
			{
				firstCol = true;
				break;
			}
		}

		for (int i = 1; i < matrix.size(); ++i)
		{
			for (int j = 0; j < matrix[i].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					this->setLeftTopZeros(matrix, i, j);
				}
			}
		}

		for (int i = 1; i < matrix[0].size(); ++i)
		{
			if (matrix[0][i] == 0)
			{
				this->setColZeros(matrix, i);
			}
		}
		for (int i = 1; i < matrix.size(); ++i)
		{
			if (matrix[i].size() > 0 && matrix[i][0] == 0)
			{
				this->setRowZeros(matrix, i);
			}
		}
		if (firstRow)
		{
			for (int i = 0; i < matrix[0].size(); ++i)
			{
				matrix[0][i] = 0;
			}
		}
		if (firstCol)
		{
			for (int i = 0; i < matrix.size(); ++i)
			{
				if (matrix[i].size() > 0)
				{
					matrix[i][0] = 0;
				}
			}
		}
		
	}
};
