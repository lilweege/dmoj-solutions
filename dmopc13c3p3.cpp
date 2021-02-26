#include <bits/stdc++.h>
using namespace std;

/*
LiSA – Crossing Field Lyrics
[Verse 1]
Mitomete ita okubyou na kako
Wakaranai mama ni kowagatte ita
Ushiro no jibun ga genjitsu wo ima ni utsusu

[Pre-Chorus]
Ikutsu mono sora wo kaita koko wa kitto
Hakanai kokoro midashite

[Chorus]
Yume de takaku tonda karada wa
Donna fuan matotte mo furiharatte iku
Nemuru chiisana omoi hirogari dashite
Kizuku yowai watashi kimi ga ireba

Kurai sekai tsuyoku ireta
Nagai yume miru kokoro wa sou eien de

[Hook]
(I want to always be with you
I'll give you everything I have)

[Verse 2]
Sagashite ita michibiku hikari
Furereba subete omoidashite
Kakegae no nai taisetsu na ima wo kureru

[Pre-Chorus]
Me wo toji sekai wo shitta
Sore wa itsumo atatakai no ni itakute

[Chorus]
[Tsunagu tashika na negai kasanari atte
Mieru mayoi wa ugoki hajimeta
Kimi wo mamoritakute seou kizu wa
Fukai nemuri no naka tadayotta

Kawaranai yakusoku datta
Futari shinjita kizuna wa sou senmei ni

[Bridge]
Koe ga todoku made namae wo yonde
Deaeta kiseki kanjitai motto

Yume de...
[Chorus]
takaku tonda karada wa
Donna fuan matotte mo furiharatte iku
Nemuru chiisana omoi hirogari dashite
Kidzuku yowai watashi kimi ga ireba

Kurai sekai tsuyoku ireta
Nagai yume miru kokoro wa sou eien de

[Outro]
(I wanna always be with you
I wanna hold you tight right now
I swear I will wipe your tears
I'll give you everything I have)
*/

int main() {
	int n, h;
	cin >> n >> h;
	
	vector<vector<int>> e(n, vector<int>(n));
	vector<vector<bool>> v(n, vector<bool>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> e[i][j];
	
	queue<pair<int, int>> q;
	q.emplace(0, 0);
	while (q.size()) {
		
		auto [i, j] = q.front();
		q.pop();
		if (v[i][j])
			continue;
		v[i][j] = true;
		
		// cout << i << " " << j << "\n";
		if (i == n - 1 && j == n - 1) {
			cout << "yes";
			return 0;
		}
		if (i < n - 1 && j < n) {
			int x = e[i][j] - e[i + 1][j];
			if (x < 0) x = -x;
			if (x <= h)
				q.emplace(i + 1, j);
		}
		if (j < n - 1 && i < n) {
			int x = e[i][j] - e[i][j + 1];
			if (x < 0) x = -x;
			if (x <= h)
				q.emplace(i, j + 1);
		}
	}
	cout << "no";
}