#include <iostream>
#include <vector>
int main()
{
	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++)
	{
		int answer = 1;
		int teams, problems, myteamid, logs;
		std::vector<std::vector<std::pair<int, int>>>teamscore;
		std::vector<std::vector<int>> totalscores;
		std::vector<std::vector<int>> problemcounts;
		std::vector<int> lognum;
		std::cin >> teams >> problems >> myteamid >> logs;

		teamscore.resize(teams);
		totalscores.resize(teams);
		problemcounts.resize(teams);
		lognum.resize(teams);
		for (int j = 0; j < logs; j++)
		{
			int maxj = 0;
			int id, problemnum, score;
			std::cin >> id >> problemnum >> score;
			//팀이 푼 문제들을 담는 벡터에 문제와 점수넣기
			teamscore[id - 1].push_back(std::make_pair(problemnum, score));
			lognum[id - 1] = (std::max(maxj, j));
		}
		//t팀부터 순서대로 돌면서
		for (int t = 0; t < teams; t++)
		{
			//t팀이 푼 문제의 갯수만큼 돌기
			int totalscore = 0;
			int cnt = 0;
			std::vector<std::vector<int>> problemscore;
			problemscore.resize(problems + 1);
			for (int p = 0; p < teamscore[t].size(); p++)
			{
				int curproblem = teamscore[t][p].first;
				int curscore = teamscore[t][p].second;
				problemscore[curproblem].push_back(curscore);
			}
			for (int w = 1; w < problemscore.size(); w++)
			{
				int maxscore = 0;
				for (int e = 0; e < problemscore[w].size(); e++)
				{
					maxscore = std::max(maxscore, problemscore[w][e]);
					cnt++;
				}
				totalscore += maxscore;
			}
			totalscores[t].push_back(totalscore);
			problemcounts[t].push_back(cnt);
		}
		for (int r = 0; r < teams; r++)
		{
			if (r == myteamid - 1)
			{
				continue;
			}
			if (totalscores[myteamid - 1] < totalscores[r])
			{
				answer++;
			}
			else if (totalscores[myteamid - 1] == totalscores[r])
			{
				if (problemcounts[myteamid - 1] > problemcounts[r])
				{
					answer++;
				}
				else if (problemcounts[myteamid - 1] == problemcounts[r])
				{
					if (lognum[myteamid - 1] > lognum[r])
					{
						answer++;
					}
				}
			}
		}
		std::cout << answer << "\n";
	}
}
