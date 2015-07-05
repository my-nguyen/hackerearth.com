import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

class Data {
	private List<Integer> in_data;
	private List<Integer> out_data;
	private int[] prime_numbers;
	private static final int PRIME_COUNT = 4;

	Data() {
		in_data = new ArrayList<Integer>();
		out_data = new ArrayList<Integer>();
		prime_numbers = new int[]{2, 3, 5, 7};
	}
	
	public void input() {
		Scanner scanner = new Scanner(System.in);
		int case_count = scanner.nextInt();
		for (int i = 0; i < case_count; i++)
			in_data.add(scanner.nextInt());
		scanner.close();
	}

	private int greatest_prime(int number) {
		for (int i = PRIME_COUNT-1; i >= 0; i--)
			if (prime_numbers[i] <= number)
				return i;
		return 0;
	}

	private int process(int number) {
		int sum = 0;
		for (int index = greatest_prime(number); number > 0; index = greatest_prime(number)) {
			sum += 1;
			number -= prime_numbers[index];
		}
		return sum;
	}

	public void process() {
		for (int number : in_data)
			out_data.add(process(number));
	}
	
	public void output() {
		for (int number : out_data)
			System.out.println(number);
	}
}

class lets_begin {
	public static void main(String[] args) {
		Data data = new Data();
		data.input();
		data.process();
		data.output();
	}
}