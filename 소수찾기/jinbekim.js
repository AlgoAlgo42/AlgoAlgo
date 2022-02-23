function isPrime(num) {
	if (num < 2) return false;
	for (let i = 2, max = Math.sqrt(num); i <= max; ++i) {
		if (num % i === 0) return false;
	}
	return true;
}

function solution(numbers) {
	let set = new Set();

	getPermutation('', [...numbers], numbers.length);
	function getPermutation(fixed, arr, len) {
		console.log('arr', arr);
		if (len === 0) return;
		for (let i = 0; i < arr.length; ++i) {
			set.add(parseInt(fixed + arr[i]));
			getPermutation(
				fixed + arr[i],
				arr.slice(0, i) + arr.slice(i + 1),
				len - 1
			);
		}
	}

	let answer = 0;
	set.forEach((val) => {
		if (isPrime(val)) {
			answer += 1;
		}
	});
	return answer;
}
