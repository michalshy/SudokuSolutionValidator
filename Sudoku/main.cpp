//
// Created by Michin on 03.01.2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int main(int argc, char* argv[])
{
    if(argc==2)
    {
        std::string path = argv[1];
        int tab[9][9];
        std::fstream file;
        file.open(path);
        if(file.is_open())
        {
            int rows = 0;
            std::string line;
            while(std::getline(file, line))
            {
                rows++;
                if(rows > 9){ std::cout<<"ERROR"<<std::endl; return 1; }
                line.erase(std::remove_if(line.begin(),line.end(), ::isspace), line.end());
                if(line.length()==9)
                {
                    for(int i = 0; i<line.length(); i++)
                    {
                        if(isdigit(line[i]))
                        {
                            if(line[i]-48>0 && line[i]-48<10)
                            {
                                tab[rows-1][i] = line[i] - 48;
                            }
                            else
                            {
                                std::cout<<"WRONG"<<std::endl; return 2;
                            }
                        }
                        else { std::cout<<"ERROR"<<std::endl; return 1; }
                    }
                }
                else
                {
                    std::cout<<"ERROR"<<std::endl;
                    return 1;
                }
            }
            if(rows<9){ std::cout<<"ERROR"<<std::endl; return 1; }
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    int row = tab[i][j];
                    int column = tab[j][i];
                    for(int k = j+1; k+2<0; k++)
                    {
                        if(row==tab[i][k])
                        {
                            std::cout<<"WRONG";
                            return 2;
                        }
                        if(column = tab[k][i])
                        {
                            std::cout<<"WRONG";
                            return 2;
                        }
                    }
                }
            }
            for(int i = 0; i < 9; i++)
            {
                if(i%3==0)
                {
                    for(int j = 0; j<9; j++)
                    {
                        if(j%3==0)
                        {
                            std::vector<int> square;
                            square.push_back(tab[i+2][j+1]);
                            square.push_back(tab[i+1][j+2]);
                            for(int k = 0; k<3; k++)
                            {
                                square.push_back(tab[i+k][j+k]);
                            }
                            for(int l = 0; l < square.size(); l++)
                            {
                                if(l+1<square.size())
                                {
                                    for(int m = l+1; m<square.size()-1; m++)
                                    {
                                        if(square[l]==square[m])
                                        {
                                            std::cout<<"WRONG"<<std::endl; return 2;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            std::cout<<"CORRECT";
        }
        else
        {
            std::cout<<"ERROR"<<std::endl;
            return 1;
        }
    }
    else
    {
        std::cout<<"ERROR"<<std::endl;
        return 1;
    }
    return 0;
}

