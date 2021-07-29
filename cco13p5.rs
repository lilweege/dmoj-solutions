#[macro_use] extern crate dmoj;

// #[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}
fn dot  (lhs: &Point, rhs: &Point) -> f32 { (lhs.x * rhs.x + lhs.y * rhs.y) as f32 }
fn cross(lhs: &Point, rhs: &Point) -> f32 { (lhs.x * rhs.y - lhs.y * rhs.x) as f32 }
fn mag  (lhs: &Point) -> f32 { ((lhs.x * lhs.x + lhs.y * lhs.y) as f32).sqrt() }

const EPSILON: f32 = 1e-4;
fn equal(a: f32, b: f32) -> bool { (a - b).abs() < EPSILON }

fn encode(p1: &Point, p2: &Point, p3: &Point) -> f32 {
	let a: Point = Point{
		x: p1.x - p2.x,
		y: p1.y - p2.y,
	};
	let b: Point = Point{
		x: p3.x - p2.x,
		y: p3.y - p2.y,
	};

	let mag_a: f32 = mag(&a);
	let mag_b: f32 = mag(&b);
	let d_prod: f32 = dot(&a, &b);
	let x_prod: f32 = cross(&a, &b);

	let angle: f32 = f32::atan2(d_prod, x_prod);
	let ratio: f32 = mag_a / mag_b;

	angle * ratio
}

fn kmp(s: &Vec<f32>, t: &Vec<f32>) -> i32 {
	let n: usize = s.len();
	let m: usize = t.len();

	let mut lps: Vec<usize> = vec![Default::default(); n];
	for i in 1..n {
		let mut j: usize = lps[i-1];
		while j > 0 && !equal(s[i], s[j]) {
			j = lps[j-1];
		}
		if equal(s[i], s[j]) {
			j += 1;
		}
		lps[i] = j;
	}

	let mut i: usize = 0;
	let mut j: usize = 0;
	while i < m {
		if equal(s[j], t[i]) {
			i += 1;
			j += 1;
		}
		if j == n {
			return (i - j) as i32;
			// j = lps[j-1];
		}
		else if i < m && !equal(s[j], t[i]) {
			if j != 0 {
				j = lps[j-1];
			}
			else {
				i += 1;
			}
		}
	}
	-1
}

fn scan_points(n: usize) -> Vec<Point> {
	(0..n)
		.map(|_| Point{
			x: scan!(i32),
			y: scan!(i32),
		})
		.collect()
}

fn solve() {
	let n: usize = scan!(usize);
	
	let v1: Vec<Point> = scan_points(n);
	let v2: Vec<Point> = scan_points(n);
	
	let s: Vec<f32> = (0..n)
		.map(|i| encode(&v1[i], &v1[(i+1)%n], &v1[(i+2)%n]))
		.collect();
	let mut t: Vec<f32> = (0..n)
		.map(|i| encode(&v2[i], &v2[(i+1)%n], &v2[(i+2)%n]))
		.collect();
	t.append(&mut t.clone());
	
	println!("{}", kmp(&s, &t)+1);
}

fn main() {
	for _ in 0..scan!(usize) {
		solve();
	}
}
