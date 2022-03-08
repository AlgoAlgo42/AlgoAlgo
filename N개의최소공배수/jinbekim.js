function gcd(num1, num2) {
	if (num2 === 0) return num1;
	return gcd(num2, num1 % num2);
}

function lcm(num1, num2) {
	return (num1 * num2) / gcd(num1, num2);
}

function solution(arr) {
	while (arr.length >= 2) {
		const num1 = arr.pop();
		const num2 = arr.pop();
		arr.push(lcm(num1, num2));
	}
	return arr[0];
}
