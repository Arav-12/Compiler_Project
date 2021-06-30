#include <bits/stdc++.h>
#include "header_CC.h"
#include "assignment_CC.tab.hpp"
using namespace std;
vector<vector<int>> game_board(5,vector<int>(5,0)); 
map<pair<int,int>,vector<string>> map_tiles;
int assign_val(int value,int x,int y)
{
        if(x<1 || x>4 || y<1 || y>4)
        {
                return OUT_OF_BOUNDS;
        }
        if(value==0)
        {
                map_tiles.erase({x,y});
        }
        game_board[x][y]=value;
        return SUCCESS;
}
void move_perform(string* oper,string* dir)
{
        string op=*oper;
        free(oper);
        string direction=*dir;
        free(dir);
        if(direction == "LEFT")
        {
                for(int i=1; i<=4; i++)
                {
                        vector<int> index;
                        vector<int> values;
                        for(int j=1; j<=4; j++)
                        {
                                if(game_board[i][j]>0)
                                {
                                        index.push_back(j);
                                        values.push_back(game_board[i][j]);
                                }
                        }
                        int pt=1;
                        for(auto u:index)
                        {
                                game_board[i][pt]=game_board[i][u];
                                if(pt!=u)
                                {
                                        game_board[i][u]=0;
                                        map_tiles.erase({i,u});
                                }
                                pt++;
                        }
                        pt=0;
                        int cnt=1;
                        while(pt<((ll)values.size()-1))
                        {
                                if(values[pt]==values[pt+1])
                                {
                                        if(op=="ADD")
                                        {
                                                game_board[i][cnt]+=game_board[i][cnt+1];
                                                for(auto u:map_tiles[{i,cnt+1}])
                                                {
                                                        map_tiles[{i,cnt}].push_back(u);
                                                }
                                                map_tiles.erase({i,cnt+1});
                                        }
                                        if(op=="SUBTRACT")
                                        { 
                                                for(int j=cnt; j<=4; j++)
                                                {
                                                        if(j+2>4)
                                                        {
                                                                game_board[i][j]=0;
                                                                if(map_tiles.count({i,j}))
                                                                        map_tiles.erase({i,j});
                                                        }
                                                        else
                                                        {
                                                                game_board[i][j]=game_board[i][j+2];
                                                                map_tiles[{i,j}]=map_tiles[{i,j+2}];
                                                        }
                                                }
                                                pt+=2;
                                                continue;
                                        }
                                        if(op=="MULTIPLY")
                                        {
                                                game_board[i][cnt]*=game_board[i][cnt+1];
                                                for(auto u:map_tiles[{i,cnt+1}])
                                                {
                                                        map_tiles[{i,cnt}].push_back(u);
                                                }
                                                map_tiles.erase({i,cnt+1});
                                        }
                                        if(op=="DIVIDE")
                                        {
                                                game_board[i][cnt]/=game_board[i][cnt+1];
                                                for(auto u:map_tiles[{i,cnt+1}])
                                                {
                                                        map_tiles[{i,cnt}].push_back(u);
                                                }
                                                map_tiles.erase({i,cnt+1});
                                        }
                                        for(int j=cnt+1; j<4; j++)
                                        {
                                                game_board[i][j]=game_board[i][j+1];
                                                map_tiles[{i,j}]=map_tiles[{i,j+1}];
                                        }
                                        pt+=2;
                                }
                                else
                                {
                                        pt++;
                                }
                                cnt++;
                        }
                        if(pt==(ll)values.size()-1)
                        {
                                cnt++;
                        }
                        for(int j=4; j>=cnt; j--)
                        {
                                game_board[i][j]=0;
                                if(map_tiles.count({i,j}))
                                        map_tiles.erase({i,j});
                        }
                }
        }
        if(direction == "DOWN")
        {
                for(int i=1; i<=4; i++)
                {
                        vector<int> index;
                        vector<int> values;
                        for(int j=4; j>=1; j--)
                        {
                                if(game_board[j][i]>0)
                                {
                                        index.push_back(j);
                                        values.push_back(game_board[j][i]);
                                }
                        }
                        int pt=4;
                        for(auto u:index)
                        {
                                game_board[pt][i]=game_board[u][i];
                                if(pt!=u)
                                {
                                        game_board[u][i]=0;
                                        map_tiles.erase({u,i});
                                }
                                pt--;
                        }
                        pt=0;
                        int cnt=4;
                        while(pt<(ll)values.size()-1)
                        {
                                if(values[pt]==values[pt+1])
                                {
                                        if(op=="ADD")
                                        {
                                                game_board[cnt][i]+=game_board[cnt-1][i];
                                                for(auto u:map_tiles[{cnt-1,i}])
                                                {
                                                        map_tiles[{cnt,i}].push_back(u);
                                                }
                                                map_tiles.erase({cnt-1,i});
                                        }
                                        if(op=="SUBTRACT")
                                        { 
                                                for(int j=cnt; j>=1; j--)
                                                {
                                                        if(j-2<1)
                                                        {
                                                                game_board[j][i]=0;
                                                                if(map_tiles.count({j,i}))
                                                                        map_tiles.erase({j,i});
                                                        }
                                                        else
                                                        {
                                                                game_board[j][i]=game_board[j-2][i];
                                                                map_tiles[{j,i}]=map_tiles[{j-2,i}];
                                                        }
                                                }
                                                pt+=2;
                                                continue;
                                        }
                                        if(op=="MULTIPLY")
                                        {
                                                game_board[cnt][i]*=game_board[cnt-1][i];
                                                for(auto u:map_tiles[{cnt-1,i}])
                                                {
                                                        map_tiles[{cnt,i}].push_back(u);
                                                }
                                                map_tiles.erase({cnt-1,i});
                                        }
                                        if(op=="DIVIDE")
                                        {
                                                game_board[cnt][i]/=game_board[cnt-1][i];
                                                for(auto u:map_tiles[{cnt-1,i}])
                                                {
                                                        map_tiles[{cnt,i}].push_back(u);
                                                }
                                                map_tiles.erase({cnt-1,i});
                                        }
                                        for(int j=cnt-1; j>1; j--)
                                        {
                                                game_board[j][i]=game_board[j-1][i];
                                                map_tiles[{j,i}]=map_tiles[{j-1,i}];
                                        }
                                        pt+=2;
                                }
                                else
                                {
                                        pt++;
                                }
                                cnt--;
                        }
                        if(pt==(ll)values.size()-1)
                        {
                                cnt--;
                        }
                        for(int j=1; j<=cnt; j++)
                        {
                                game_board[j][i]=0;
                                if(map_tiles.count({j,i}))
                                        map_tiles.erase({j,i});
                        }
                }
        }
        if(direction == "RIGHT")
        {
                for(int i=1; i<=4; i++)
                {
                        vector<int> index;
                        vector<int> values;
                        for(int j=4; j>=1; j--)
                        {
                                if(game_board[i][j]>0)
                                {
                                        index.push_back(j);
                                        values.push_back(game_board[i][j]);
                                }
                        }
                        int pt=4;
                        for(auto u:index)
                        {
                                game_board[i][pt]=game_board[i][u];
                                if(pt!=u)
                                {
                                        game_board[i][u]=0;
                                        map_tiles.erase({i,u});
                                }
                                pt--;
                        }
                        pt=0;
                        int cnt=4;
                        while(pt<(ll)values.size()-1)
                        {
                                if(values[pt]==values[pt+1])
                                {
                                        if(op=="ADD")
                                        {
                                                game_board[i][cnt]+=game_board[i][cnt-1];
                                                for(auto u:map_tiles[{i,cnt-1}])
                                                {
                                                        map_tiles[{i,cnt}].push_back(u);
                                                }
                                                map_tiles.erase({i,cnt-1});
                                        }
                                        if(op=="SUBTRACT")
                                        { 
                                                for(int j=cnt; j>=1; j--)
                                                {
                                                        if(j-2<1)
                                                        {
                                                                game_board[i][j]=0;
                                                                if(map_tiles.count({i,j}))
                                                                        map_tiles.erase({i,j});
                                                        }
                                                        else
                                                        {
                                                                game_board[i][j]=game_board[i][j-2];
                                                                map_tiles[{i,j}]=map_tiles[{i,j-2}];
                                                        }
                                                }
                                                pt+=2;
                                                continue;
                                        }
                                        if(op=="MULTIPLY")
                                        {
                                                game_board[i][cnt]*=game_board[i][cnt-1];
                                                for(auto u:map_tiles[{i,cnt-1}])
                                                {
                                                        map_tiles[{i,cnt}].push_back(u);
                                                }
                                                map_tiles.erase({i,cnt-1});
                                        }
                                        if(op=="DIVIDE")
                                        {
                                                game_board[i][cnt]/=game_board[i][cnt-1];
                                                for(auto u:map_tiles[{i,cnt-1}])
                                                {
                                                        map_tiles[{i,cnt}].push_back(u);
                                                }
                                                map_tiles.erase({i,cnt-1});
                                        }
                                        for(int j=cnt-1; j>1; j--)
                                        {
                                                game_board[i][j]=game_board[i][j-1];
                                                map_tiles[{i,j}]=map_tiles[{i,j-1}];
                                        }
                                        pt+=2;
                                }
                                else
                                {
                                        pt++;
                                }
                                cnt--;
                        }
                        if(pt==(ll)values.size()-1)
                        {
                                cnt--;
                        }
                        for(int j=1; j<=cnt; j++)
                        {
                                game_board[i][j]=0;
                                if(map_tiles.count({i,j}))
                                        map_tiles.erase({i,j});
                        }
                }
        }
        if(direction == "UP")
        {
                for(int i=1; i<=4; i++)
                {
                        vector<int> index;
                        vector<int> values;
                        for(int j=1; j<=4; j++)
                        {
                                if(game_board[j][i]>0)
                                {
                                        index.push_back(j);
                                        values.push_back(game_board[j][i]);
                                }
                        }
                        int pt=1;
                        for(auto u:index)
                        {
                                game_board[pt][i]=game_board[u][i];
                                if(pt!=u)
                                {
                                        game_board[u][i]=0;
                                        map_tiles.erase({u,i});
                                }
                                pt++;
                        }
                        pt=0;
                        int cnt=1;
                        while(pt<(ll)values.size()-1)
                        {
                                if(values[pt]==values[pt+1])
                                {
                                        if(op=="ADD")
                                        {
                                                game_board[cnt][i]+=game_board[cnt+1][i];
                                                for(auto u:map_tiles[{cnt+1,i}])
                                                {
                                                        map_tiles[{cnt,i}].push_back(u);
                                                }
                                                map_tiles.erase({cnt+1,i});
                                        }
                                        if(op=="SUBTRACT")
                                        { 
                                                for(int j=cnt; j<=4; j++)
                                                {
                                                        if(j+2>4)
                                                        {
                                                                game_board[j][i]=0;
                                                                if(map_tiles.count({j,i}))
                                                                        map_tiles.erase({j,i});
                                                        }
                                                        else
                                                        {
                                                                game_board[j][i]=game_board[j+2][i];
                                                                map_tiles[{j,i}]=map_tiles[{j+2,i}];
                                                        }
                                                }
                                                pt+=2;
                                                continue;
                                        }
                                        if(op=="MULTIPLY")
                                        {
                                                game_board[cnt][i]*=game_board[cnt+1][i];
                                                for(auto u:map_tiles[{cnt+1,i}])
                                                {
                                                        map_tiles[{cnt,i}].push_back(u);
                                                }
                                                map_tiles.erase({cnt+1,i});
                                        }
                                        if(op=="DIVIDE")
                                        {
                                                game_board[cnt][i]/=game_board[cnt+1][i];
                                                for(auto u:map_tiles[{cnt+1,i}])
                                                {
                                                        map_tiles[{cnt,i}].push_back(u);
                                                }
                                                map_tiles.erase({cnt+1,i});
                                        }
                                        for(int j=cnt+1; j<4; j++)
                                        {
                                                game_board[j][i]=game_board[j+1][i];
                                                map_tiles[{j,i}]=map_tiles[{j+1,i}];
                                        }
                                        pt+=2;
                                }
                                else
                                {
                                        pt++;
                                }
                                cnt++;
                        }
                        if(pt==(ll)values.size()-1)
                        {
                                cnt++;
                        }
                        for(int j=4; j>=cnt; j--)
                        {
                                game_board[j][i]=0;
                                if(map_tiles.count({j,i}))
                                        map_tiles.erase({j,i});
                        }
                }
        }
        random_tile();
}
int name_setter(string* name,int x,int y)
{
        string curr=*name;
        if(game_board[x][y]==0)
        {
                return FAILURE;
        }
        for(int i=1; i<=4; i++)
        {
            for(int j=1; j<=4; j++)
            {
                for(auto u:map_tiles[{i,j}])
                {
                    if(u==curr)
                    {
                        return FAILURE;
                    }
                }
            }
        }
        map_tiles[{x,y}].push_back(curr);
        free(name);
        return SUCCESS;
}
int query_value(int x,int y)
{
        if(x<1 || x>4 || y<1 || y>4)
        {
                return OUT_OF_BOUNDS;
        }
        cout<<" "<<game_board[x][y]<<'\n';
        return SUCCESS;
}
void random_tile()
{
        srand(time(0));
        int flg=0;
        for(int i=1;i<5;i++)
        {
                for(int j=1;j<5;j++)
                {
                        if(game_board[i][j]==0)
                        {
                                flg=1;
                                break;
                        }                
                }
                if(flg==1)
                {
                        break;
                }
        }
        if(flg==1)
        {
                int x,y;
                while(true)
                {
                        x= rand()%4;
                        x++;
                        y= rand()%4;
                        y++;
                        if(game_board[x][y]==0)
                        {
                                break;
                        }
                }
                int value = (rand()%2)*2+2;
                assign_val(value,x,y);
        }
}
int result(int err_val)
{
        if(err_val==0)
        {
                for(int i=1;i<=4;i++)
                {
                        for(int j=1;j<=4;j++)
                        {
                                fprintf(stderr,"%d\40",game_board[i][j]);
                        }
                }
                for(int i=1;i<=4;i++)
                {
                        for(int j=1;j<=4;j++)
                        {
                                if(map_tiles.find({i,j})!=map_tiles.end())
                                {
                                        pair<int,int> posn = {i,j};
                                        for(auto x:map_tiles[posn])
                                        {
                                                fprintf(stderr,"%d,%d",i,j);
                                                char *ans = &x[0];
                                                fprintf(stderr,"%s\40",ans);
                                        }
                                }  
                        }
                }
                fprintf(stderr,"\n");
        }
        else
        {
                fprintf(stderr,"-1\n");
        }
        return 0;
}       
void UI()
{
        for(int i=1;i<=4;i++)
        {
            cout<<"------------------------------------------------------------------\n";
                cout<<"|\t";
                for(int j=1;j<=4;j++)
                {
                        if(game_board[i][j]!=0)
                                cout<<game_board[i][j]<<"\t|\t";
                        else
                                cout<<" "<<"\t|\t";
                }
                cout<<"\n";
        }
        cout<<"------------------------------------------------------------------\n";
}
void init()
{
        cout<<"GAME> A 2048 GAME .\nGAME> TYPE THE COMMANDS ENDING WITH'.'\nKEYWORDS IN CAPITAL LETTERS.\n";
        for(int i=1;i<=4;i++)
        {
                for(int j=1;j<=4;j++)
                {
                        game_board[i][j]=0;
                        map_tiles[{i,j}].clear();
                }
        }
        random_tile();
        UI();
}
int main()
{
        init();
        while(1)
        {
                printf("GAME> Please type a command.\n");
                printf("----->");
                yyparse();
                UI();
        }
return 0;
}