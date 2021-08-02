#!/usr/bin/env python3

from dataclasses import dataclass
from subprocess import Popen, PIPE, STDOUT
import random

class Proc:
	def __init__(self, cmd):
		self.__sp = Popen(cmd.split(), stdout=PIPE, stdin=PIPE, stderr=STDOUT)

	def put(self, s):
		self.__sp.stdin.write(s.encode())
		self.__sp.stdin.flush()
	
	def get(self):
		return self.__sp.stdout.readline()

@dataclass(order=True)
class rect:
	x1: int
	x2: int
	y1: int
	y2: int

	def inside(self, a, b, c, d):
		return (
			self.x1 >= a and
			self.x2 <= b and
			self.y1 >= c and
			self.y2 <= d)

	def __repr__(self):
		return f"{self.x1} {self.x2} {self.y1} {self.y2}"

class Grader:
	def __init__(self):
		def rand_test(n_max=500, m_max=1e9):
			def rand_rect(max):
				x1 = random.randint(1, max)
				x2 = random.randint(x1, max)
				y1 = random.randint(1, max)
				y2 = random.randint(y1, max)
				return rect(x1, x2, y1, y2)
			return [rand_rect(m_max) for _ in range(random.randint(1, n_max))]

		self.tests = [
			[
				# sample
				rect(2, 2, 3, 3),
				rect(4, 7, 5, 8),
				rect(3, 5, 3, 5),
				rect(3, 5, 3, 5),
				rect(1, 5, 2, 5),
			],
			[
				rect(5, 6, 8, 8),
				rect(6, 6, 5, 10),
			],
			[
				rect(6, 10, 10, 10),
				rect(9, 10, 1, 2),
			],
			[
				rect(8, 8, 1, 3),
			],
			[
				rect(4, 9, 1, 1),
				rect(4, 9, 5, 6),
			],
			[
				rect(5, 9, 2, 9),
				rect(5, 9, 5, 8),
			],
		] + [rand_test(n_max=20, m_max=10) for _ in range(500)
		] + [rand_test(m_max=10) for _ in range(50)
		] + [rand_test() for _ in range(20)]
	
	def __iter__(self):
		yield from self.tests
	
	@staticmethod
	def query(test, a, b, c, d):
		# sufficient for small cases
		return sum(r.inside(a, b, c, d) for r in test)


def main():
	g = Grader()
	for idx, test in enumerate(g, 1):
		p = Proc("./a.out")
		p.put(f"{len(test)}\n")

		while True:
			query = p.get()
			q, *r = query.split()
			if q == b'!':
				res = ""
				while (ans := p.get()):
					res += ans.decode()
				
				expected = sorted(test)
				got = sorted(rect(*map(int, row.split())) for row in res.split("\n")[:-1])
				passed = expected == got
				print(f"test {idx}: ", end="")
				print('AC' if passed else 'WA')
				if not passed:
					print("EXPECTED")
					print("\n".join(repr(r) for r in expected))
					print("GOT")
					print("\n".join(repr(r) for r in got))
					exit(0)
				
				break
			
			p.put(f"{Grader.query(test, *map(int, r))}\n")


if __name__ == "__main__":
	main()