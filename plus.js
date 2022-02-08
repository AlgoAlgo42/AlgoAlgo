function solution(numbers) {
	return 45 - numbers.reduce((answer, val) => answer + val);
}
