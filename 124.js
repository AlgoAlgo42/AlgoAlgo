function solution(n) {
	var answer = '';

	while (n) {
		answer = '412'[n % 3] + answer;
		n = Math.floor((n - 1) / 3);
	}
	return answer;
}
