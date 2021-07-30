#include <bits/stdc++.h>
using namespace std;

/*
CCC has become terrible in recent years, thanks to Mr. Troy Vasiga and his team. Lots of server issues and crashes on the main CCC site since at least 2016. Some of them were blamed on the public. This doesn't happen in other programming contests but they got away with it because they didn't provide proper data to back their claims. It is easier to blame your server crashes on the users, your team, or the wind blowing than learn a bit about load balancing to prevent overloading your servers.

This must have emboldened them to make the 2018 and 2019 Senior contests a disaster. Take for example Problem S3 in 2019 - Arithmetic Square. It has an efficient solution using advanced math such as linear algebra, matrices and Gaussian elimination. However, these subjects are not in the Canadian high school math curricula, let alone computer studies. Even grade 12 Calculus and Vectors AP doesn't touch these.

In fact, linear algebra and Gaussian elimination are both SPECIFICALLY EXCLUDED from the IOI syllabus, and have been so for many years. See here, on page 8: https://people.ksp.sk/~misof/ioi-syllabus/ioi-syllabus.pdf

Maybe there are other ways to solve it but they'd be extremely contorted. Linear algebra provides a decisive advantage. Unsuspecting kids who attempt to circumvent or reinvent linear algebra will burn out their entire contest time and more. After all, it took Gauss some years to invent Gaussian elimination.

The other problems in 2019 CCC Senior are equally out of whack. Either graduate level math research, like algorithms for the famous Goldbach conjecture, or endless debugging like the question with the triangles. No fun graphs or trees which make up the majority of the IOI syllabus.

Since the organizers clearly didn't design this contest for a good IOI selection, nor to encourage the participants, they look like a bunch of one-trick-ponies who have ruined the contest on purpose. They get to look like geniuses to the corporate sponsors. You know, they get to show they are much smarter than the kids who couldn't invent on the spot all the advanced math that some of the organizers learned in university.

Considering that CCC participants will soon compete with the CCC organizers for jobs and grants, botching the contest in 2016-2019 was a clever strategy for the organizers. They also got to make their favorites win by knocking down everyone else with unfair subject matter and server issues. Or maybe not?

We'll see if the powers that be are willing to fix the 2019 CCC botch. They need to get someone more responsible to redo the contest and properly select the IOI team. This contest used to run smoothly before Troy Vasiga took over and wasted it year after year after year. CCC is a tremendous asset for Canadian education, it is important for thousands and thousands of students each year, and it deserves honest and competent leadership.
*/


// passes 15/15 for original ccc data
// fails dmoj additional subtask

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	const int UNSET = 1000000000-1;

	array<array<int, 3>, 3> m;
	int n = 0;
	auto done = [&]() {
		for (auto r : m) {
			for (auto e : r)
				cout << e << " ";
			cout << "\n";
		}
		exit(0);
	};
	auto try_done = [&]() {
		assert(n <= 9);
		if (n != 9)
			return;
		done();
	};
	

	auto ok = [&](int e) {
		return e != UNSET;
	};

	auto set = [&](int& e, int v) {
		++n;
		e = v;
	};

	for (auto& r : m) {
		for (auto& e : r) {
			string s;
			cin >> s;
			if (s == "X") {
				e = UNSET;
			}
			else {
				set(e, stoi(s));
			}
		}
	}

	if (n == 0) {
		n = 9;
		done();
	}	
	if (n == 1) {
		auto get_one = [&]() {
			for (auto r : m)
				for (auto e : r)
					if (e != UNSET)
						return e;
			return -1;
		};
		int x = get_one();
		for (auto& r : m)
			for (auto& e : r)
				if (e != x)
					set(e, x);
		done();
	}

	auto trivial = [&]() {
		for (int _ = 0; _ < 2; ++_) {
			for (int i = 0; i < 3; ++i) {
				if (ok(m[i][1]) && ok(m[i][2]) && !ok(m[i][0]))
					set(m[i][0], 2 * m[i][1] - m[i][2]);
				if (ok(m[i][0]) && ok(m[i][2]) && !ok(m[i][1]))
					set(m[i][1], (m[i][0] + m[i][2]) / 2);
				if (ok(m[i][0]) && ok(m[i][1]) && !ok(m[i][2]))
					set(m[i][2], 2 * m[i][1] - m[i][0]);
			}
			for (int j = 0; j < 3; ++j) {
				if (ok(m[1][j]) && ok(m[2][j]) && !ok(m[0][j]))
					set(m[0][j], 2 * m[1][j] - m[2][j]);
				if (ok(m[0][j]) && ok(m[2][j]) && !ok(m[1][j]))
					set(m[1][j], (m[0][j] + m[2][j]) / 2);
				if (ok(m[0][j]) && ok(m[1][j]) && !ok(m[2][j]))
					set(m[2][j], 2 * m[1][j] - m[0][j]);
			}
		}
	};

	trivial();
	try_done();

	auto fill = [&]() {
		if (ok(m[0][0]) && ok(m[0][1]) && ok(m[0][2])) {
			int d = m[0][1] - m[0][0];
			if (ok(m[1][0])) {
				set(m[1][1], m[1][0] + d);
			}
			else if (ok(m[1][1])) {
				set(m[1][0], m[1][1] - d);
			}
			else if (ok(m[1][2])) {
				set(m[1][1], m[1][2] - d);
			}
			else {
				set(m[1][0], m[0][0]);
				set(m[2][0], m[0][0]);
				set(m[1][1], m[0][1]);
				set(m[2][1], m[0][1]);
				set(m[1][2], m[0][2]);
				set(m[2][2], m[0][2]);
				done();
			}
		}
		else if (ok(m[1][0]) && ok(m[1][1]) && ok(m[1][2])) {
			int d = m[1][1] - m[1][0];
			if (ok(m[0][0])) {
				set(m[0][1], m[0][0] + d);
			}
			else if (ok(m[0][1])) {
				set(m[0][0], m[0][1] - d);
			}
			else if (ok(m[0][2])) {
				set(m[0][1], m[0][2] - d);
			}
			else {
				set(m[0][0], m[1][0]);
				set(m[2][0], m[1][0]);
				set(m[0][1], m[1][1]);
				set(m[2][1], m[1][1]);
				set(m[0][2], m[1][2]);
				set(m[2][2], m[1][2]);
				done();
			}
		}
		else if (ok(m[2][0]) && ok(m[2][1]) && ok(m[2][2])) {
			int d = m[2][1] - m[2][0];
			if (ok(m[1][0])) {
				set(m[1][1], m[1][0] + d);
			}
			else if (ok(m[1][1])) {
				set(m[1][0], m[1][1] - d);
			}
			else if (ok(m[1][2])) {
				set(m[1][1], m[1][2] - d);
			}
			else {
				set(m[1][0], m[2][0]);
				set(m[0][0], m[2][0]);
				set(m[1][1], m[2][1]);
				set(m[0][1], m[2][1]);
				set(m[1][2], m[2][2]);
				set(m[0][2], m[2][2]);
				done();
			}
		}
		else if (ok(m[0][0]) && ok(m[1][0]) && ok(m[2][0])) {
			int d = m[1][0] - m[0][0];
			if (ok(m[0][1])) {
				set(m[1][1], m[0][1] + d);
			}
			else if (ok(m[1][1])) {
				set(m[0][1], m[1][1] - d);
			}
			else if (ok(m[2][1])) {
				set(m[1][1], m[2][1] - d);
			}
			else {
				set(m[0][1], m[0][0]);
				set(m[0][2], m[0][0]);
				set(m[1][1], m[1][0]);
				set(m[1][2], m[1][0]);
				set(m[2][1], m[2][0]);
				set(m[2][2], m[2][0]);
				done();
			}
		}
		else if (ok(m[0][1]) && ok(m[1][1]) && ok(m[2][1])) {
			int d = m[1][1] - m[0][1];
			if (ok(m[0][0])) {
				set(m[1][0], m[0][0] + d);
			}
			else if (ok(m[1][0])) {
				set(m[0][0], m[1][0] - d);
			}
			else if (ok(m[2][0])) {
				set(m[1][0], m[2][0] - d);
			}
			else {
				set(m[0][0], m[0][1]);
				set(m[0][2], m[0][1]);
				set(m[1][0], m[1][1]);
				set(m[1][2], m[1][1]);
				set(m[2][0], m[2][1]);
				set(m[2][2], m[2][1]);
				done();
			}
		}
		else if (ok(m[0][2]) && ok(m[1][2]) && ok(m[2][2])) {
			int d = m[1][2] - m[0][2];
			if (ok(m[0][1])) {
				set(m[1][1], m[0][1] + d);
			}
			else if (ok(m[1][1])) {
				set(m[0][1], m[1][1] - d);
			}
			else if (ok(m[2][1])) {
				set(m[1][1], m[2][1] - d);
			}
			else {
				set(m[0][1], m[0][2]);
				set(m[0][0], m[0][2]);
				set(m[1][1], m[1][2]);
				set(m[1][0], m[1][2]);
				set(m[2][1], m[2][2]);
				set(m[2][0], m[2][2]);
				done();
			}
		}
	};

	fill();
	trivial();
	try_done();


	// n == 2 || n == 3
	bool corner =
		(ok(m[0][0]) && ok(m[2][2])) ||
		(ok(m[0][2]) && ok(m[2][0]));
	if (corner) {
		if (!ok(m[1][1]))
			m[1][1] = 0;
		set(m[0][1], m[1][1]);
		trivial();
		done();
	}

	bool diag =
		(ok(m[0][0]) + ok(m[1][1]) + ok(m[2][2])) >= 2 ||
		(ok(m[0][2]) + ok(m[1][1]) + ok(m[2][0])) >= 2;
	if (diag) {
		if (ok(m[0][0]) || ok(m[0][2]))
			set(m[0][1], m[1][1]);
		else if (ok(m[2][2]) || ok(m[2][0]))
			set(m[2][1], m[1][1]);
		trivial();
		fill();
		trivial();
		done();
	}
	
	
	if (n == 2) {
		// corner and opposite middle
		// and rotations

		// X A X
		// X X X
		// X X B

		// X A X
		// X X X
		// B X X

		int A;
		if ((A = ok(m[0][1])) && (ok(m[2][2]) || ok(m[2][0])) ||
			(A = ok(m[1][2])) && (ok(m[2][0]) || ok(m[0][0])) ||
			(A = ok(m[2][1])) && (ok(m[0][0]) || ok(m[2][0])) ||
			(A = ok(m[1][0])) && (ok(m[0][2]) || ok(m[2][2]))) {
			set(m[1][1], A);
			trivial();
			fill();
			trivial();
			done();
		}
	}

	// X A X
	// B X X
	// X X C

	// X A X
	// X X B
	// C X X


	// X B X // dup
	// X X A
	// C X X

	// C X X
	// X X A
	// X B X


	// X X C
	// B X X
	// X A X

	// C X X // dup
	// X X B
	// X A X


	// X B X // dup
	// A X X
	// X X C

	// X X C // dup
	// A X X
	// X B X

	if (ok(m[0][1]) && ok(m[1][0]) && ok(m[2][2]) ||
		ok(m[0][1]) && ok(m[1][2]) && ok(m[2][0]) ||
		ok(m[2][1]) && ok(m[0][0]) && ok(m[1][2]) ||
		ok(m[2][1]) && ok(m[0][2]) && ok(m[1][0])) {
		if (ok(m[0][1]))
			set(m[1][1], m[0][1]);
		else if (ok(m[0][1]))
			set(m[1][1], m[0][1]);
		else if (ok(m[2][1]))
			set(m[1][1], m[2][1]);
		else
			set(m[1][1], m[2][1]);
		trivial();
		done();
	}


	// shouldn't get here
	// return 0;

	// while (true);
	for (auto r : m) {
		for (auto e : r)
			if (ok(e))
				cout << e << " ";
			else
				cout << "X ";
		cout << "\n";
	}
}
