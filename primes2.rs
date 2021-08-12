#[macro_use] extern crate dmoj;

// this problem is identical to phantom3
fn main() {

	let n: i64 = scan!(i64);
	let m: i64 = scan!(i64);

	let mut primes: Vec<i64> = Vec::with_capacity(100000);
	let mut sieve: Vec<bool> = vec![true; 5000010];
	

	let lim: usize = (m as f32).sqrt() as usize;
	
	for i in (3..lim+1).step_by(2) {
		if sieve[i] {
			for j in (i*i..(lim as usize)).step_by(i) {
				sieve[j] = false;
			}
			primes.push(i as i64);
		}
	}
	let mut sieve: Vec<bool> = vec![true; 5000010];

	for prime in primes.iter() {
		let mut low_lim = n / prime * prime;
		if low_lim < n {
			low_lim += prime;
		}
		for j in (low_lim..m).step_by(*prime as usize) {
			sieve[(j-n) as usize] = false;
		}
		if n <= *prime && *prime < m {
			sieve[(prime-n) as usize] = true;
		}
	}
	
	if n <= 2 {
		println!("2");
	}
	for i in ((if n%2==0 {n+1} else {n})..m).step_by(2) {
		if i == 1 {
			continue;
		}
		if sieve[(i-n) as usize] {
			println!("{}", i);
		}
	}
}