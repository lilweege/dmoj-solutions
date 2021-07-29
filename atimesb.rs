#[macro_use] extern crate dmoj;
use std::io::{self};

// use num::complex::Complex64;
// this is not allowed

use std::ops::*;
#[derive(Default, Clone, Copy)]
struct Complex64 {
	re: f64,
	im: f64,
}
impl Add for Complex64 {
	type Output = Complex64;
	fn add(self, rhs: Complex64) -> Complex64 { Complex64{ re: self.re + rhs.re, im: self.im + rhs.im, } }
}
impl Neg for Complex64 {
	type Output = Complex64;
	fn neg(self) -> Complex64 { Complex64{ re: -self.re, im: -self.im, } }
}
impl Sub for Complex64 {
	type Output = Complex64;
	fn sub(self, rhs: Complex64) -> Complex64 { self + -rhs }
}
impl Mul for Complex64 {
	type Output = Complex64;
	fn mul(self, rhs: Complex64) -> Complex64 {
		Complex64{
			re: self.re * rhs.re - self.im * rhs.im,
			im: self.re * rhs.im + self.im * rhs.re,
		}
	}
}
impl MulAssign for Complex64 {
	fn mul_assign(&mut self, rhs: Complex64) { *self = *self * rhs; }
}
impl Div<f64> for Complex64 {
	type Output = Complex64;
	fn div(self, rhs: f64) -> Complex64 { Complex64{ re: self.re / rhs, im: self.im / rhs, } }
}
impl DivAssign<f64> for Complex64 {
	fn div_assign(&mut self, rhs: f64) { *self = *self / rhs; }
}


fn fft(p: &mut Vec<Complex64>, mut n: usize) {
	n /= 2;
	if n == 0 {
		return;
	}

	let mut p_e: Vec<Complex64> = (0..n).map(|i| p[i * 2    ]).collect();
	let mut p_o: Vec<Complex64> = (0..n).map(|i| p[i * 2 + 1]).collect();
	
	fft(&mut p_e, n);
	fft(&mut p_o, n);
	
	let a: f64 = std::f64::consts::PI / n as f64;
	let w: Complex64 = Complex64{ re: a.cos(), im: a.sin(), };
	let mut wi: Complex64 = Complex64{ re: 1.0, im: 0.0, };
	for i in 0..n {
		p[i  ] = p_e[i] + wi * p_o[i];
		p[i+n] = p_e[i] - wi * p_o[i];
		wi *= w;
	}
}

fn ifft(p: &mut Vec<Complex64>, mut n: usize) {
	n /= 2;
	if n == 0 {
		return;
	}

	let mut p_e: Vec<Complex64> = (0..n).step_by(2).map(|i| p[i]).collect();
	let mut p_o: Vec<Complex64> = (1..n).step_by(2).map(|i| p[i]).collect();

	ifft(&mut p_e, n);
	ifft(&mut p_o, n);
	
	let a: f64 = -std::f64::consts::PI / n as f64;
	let w: Complex64 = Complex64{ re: a.cos(), im: a.sin(), };
	let mut wi: Complex64 = Complex64{ re: 1.0, im: 0.0, };
	for i in 0..n {
		p[i  ] = p_e[i] + wi * p_o[i];
		p[i+n] = p_e[i] - wi * p_o[i];
		wi *= w;
	}
}


fn add(x_c: &mut Vec<Complex64>, y_c: &mut Vec<Complex64>) -> Vec<i32> {
	let n: usize = ((x_c.len() + y_c.len()) as f64).log2().ceil().exp2() as usize;
	
	x_c.resize(n, Complex64::default());
	y_c.resize(n, Complex64::default());
	
	fft(x_c, n);
	fft(y_c, n);
	let z_c = x_c;
	for (i, z) in z_c.iter_mut().enumerate() {
		*z *= y_c[i];
	}
	ifft(z_c, n);
	for z in z_c.iter_mut() {
		*z /= n as f64;
	}

	let mut carry: i32 = 0;
	let mut z_r: Vec<i32> = vec![0; n];
	for i in 0..n {
		z_r[i] = (z_c[i].re).round() as i32 + carry;
		carry = z_r[i] / 10;
		z_r[i] %= 10;
	}
	z_r
}

fn print(v: &Vec<i32>) {
	let mut it = v.iter().rev();
	let x: Option<&i32> = it.find(|&&x| x != 0);
	if x.is_none() {
		println!("0");
	}
	else {
		print!("{}", x.unwrap());
		for &x in it {
			print!("{}", x);
		}
		println!("");
	}
}

fn poly(strn: &String) -> Vec<Complex64> {
	strn.as_bytes().iter().rev()
		.map(|b| Complex64{
			re: (b - '0' as u8) as f64,
			im: 0.0,
		})
		.collect()
}

fn main() -> io::Result<()> {
	let mut s1: String = String::new();
	let mut s2: String = String::new();
	let stdin = io::stdin();
	stdin.read_line(&mut s1)?; s1.pop();
	stdin.read_line(&mut s2)?; s2.pop();

	print(&add(&mut poly(&s1), &mut poly(&s2)));

	Ok(())
}
