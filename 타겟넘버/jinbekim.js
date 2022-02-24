function solution(numbers, target) {
	return dp(0, 0, numbers, target);
}

const dp = (idx, sum, numbers, target) => {
	if (idx === numbers.length) {
		return target === sum ? 1 : 0;
	}

	let result = 0;

	result = dp(idx + 1, sum + numbers[idx], numbers, target, result);
	result += dp(idx + 1, sum - numbers[idx], numbers, target, result);
	return result;
};

console.log(solution([4, 1, 2, 1], 4));
