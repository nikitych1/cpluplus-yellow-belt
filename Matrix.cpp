#include <vector>
#include <cassert>
#include <iostream>

class Matrix
{
public:
    Matrix()
    {
        _data.assign(0, std::vector<int>(0));
        rows = 0;
        cols = 0;
    }

    Matrix(int num_rows, int num_cols)
    {
        rows = num_rows;
        cols = num_cols;

        if (rows < 0 || cols < 0)
            throw std::out_of_range("neg idxs");

        _data.resize(rows);

        for (auto& row : _data)
            row.resize(cols);
    }

    void Reset(int num_rows, int num_cols)
    {
        if (num_rows < 0 || num_cols < 0)
            throw std::out_of_range("neg idxs");

        rows = num_rows;
        cols = num_cols;

        _data.resize(rows);

        for (auto & i : _data)
        {
            i.resize(cols);
            std::fill(i.begin(), i.end(), 0);
        }
    }

    int At(int num_rows, int num_cols) const
    {
        if (num_rows < 0 || num_cols < 0)
            throw std::out_of_range("neg idxs");

        if (num_rows > rows || num_cols > cols)
            throw std::out_of_range("big idxs");

        return _data.at(num_rows).at(num_cols);
    }

    int& At(int num_rows, int num_cols)
    {
        if (num_rows < 0 || num_cols < 0)
            throw std::out_of_range("neg idxs");

        if (num_rows > rows || num_cols > cols)
            throw std::out_of_range("big idxs");

        return _data.at(num_rows).at(num_cols);
    }

    size_t GetNumRows() const { return rows; }

    size_t GetNumColumns() const { return cols; }

    std::vector<std::vector<int>>& GetData() { return _data; }

    const std::vector<std::vector<int>>& GetData() const { return _data; }

    friend std::istream &operator>>(std::istream &input, Matrix &mat)
    {
        size_t t_cols = mat.GetNumColumns();
        size_t t_rows = mat.GetNumRows();

        if (t_cols == 0 && t_rows == 0)
        {
            std::cin >> t_rows >> t_cols;
            mat = Matrix(t_rows, t_cols);
        }

        auto& data = mat.GetData();

        for (size_t i = 0; i < t_rows; ++i)
        {
            for (size_t j = 0; j < t_cols; ++j)
            {
                auto& row = data.at(i);
                int value = 0;
                input >> value;
                row.insert(row.begin() + j, value);
            }
        }

        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, const Matrix& mat)
    {
        const auto& t_data = mat.GetData();
        size_t t_cols = mat.GetNumColumns();
        size_t t_rows = mat.GetNumRows();

        for (size_t i = 0; i < t_rows; ++i)
        {
            for (size_t j = 0; j < t_cols; ++j)
            {
                auto row = t_data.at(i);
                output << row.at(j) << " ";

                if (j == t_cols - 1)
                    std::cout << std::endl;
            }
        }

        return output;
    }

    bool operator==(const Matrix& mat) const
    {
        if (this->GetNumColumns() == mat.GetNumColumns()
            && this->GetNumRows() == mat.GetNumRows())
        {
            for (size_t i = 0; i < mat.GetNumColumns(); ++i)
            {
                for (size_t j = 0; j < mat.GetNumRows(); ++j)
                {
                    if (mat.At(i, j) != this->At(i, j))
                        return false;
                }
            }

            return true;
        }

        return false;
    }

    Matrix operator+(const Matrix& mat)
    {
        if (this->GetNumColumns() != mat.GetNumColumns()
            || this->GetNumRows() != mat.GetNumRows())
            throw std::invalid_argument("my god i see only darkness around me");

        size_t t_rows = this->GetNumRows();
        size_t t_cols = this->GetNumColumns();

        Matrix t_mat(t_rows, t_cols);

        for (size_t i = 0; i < t_rows; ++i)
            for (size_t j = 0; j < t_cols; ++j)
                t_mat.At(i, j) = mat.At(i, j) + this->At(i, j);

        return t_mat;
    }

private:
    std::vector<std::vector<int>> _data;
    size_t rows;
    size_t cols;
};


int main()
{
    Matrix one, two;
    std::cin >> one >> two;

    std::cout << one + two << std::endl;

    return 0;
}