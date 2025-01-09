use std::io::{stdin, stdout, BufWriter, Write};

fn main() {
    let stdout = stdout();
    let mut writer = BufWriter::new(stdout);

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();

	let weight = input.trim().parse::<f64>().unwrap();

    let mut input = String::new();
    stdin().read_line(&mut input).unwrap();
	
    let height = input.trim().parse::<f64>().unwrap();
	
	let BMI = weight / (height * height);
	
	if BMI > 25.0 {
		writeln!(writer, "Overweight").unwrap();
	}
	else if BMI < 18.5 {
		writeln!(writer, "Underweight").unwrap();
	}
	else {
		writeln!(writer, "Normal weight").unwrap();
	}
}