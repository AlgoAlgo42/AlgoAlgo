function solution(n) {
	var answer = 0;
	let i = 1,
		max = parseInt(n / 2) + 1;
	while (i <= max) {
		let sum = n;
		for (let j = i; sum > 0; ++j) {
			sum -= j;
		}
		if (sum === 0) answer += 1;
		i++;
	}
	answer += 1; //자기자신
	return answer;
}
