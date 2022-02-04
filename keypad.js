function ab(num) {
	return num > 0 ? num : -num;
}
function solution(numbers, hand) {
	var answer = '';
	let leftThumb = 10;
	let rightThumb = 12;

	numbers.forEach((num) => {
		if (num === 0) num = 11;
		if (num % 3 === 1) {
			answer += 'L';
			leftThumb = num;
		} else if (num % 3 === 0) {
			answer += 'R';
			rightThumb = num;
		} else {
			const left =
				parseInt(ab(leftThumb - num) / 3) + (ab(leftThumb - num) % 3);
			const right =
				parseInt(ab(rightThumb - num) / 3) + (ab(rightThumb - num) % 3);
			if (hand === 'right') {
				if (left >= right) {
					answer += 'R';
					rightThumb = num;
				} else {
					answer += 'L';
					leftThumb = num;
				}
			} else {
				if (left <= right) {
					answer += 'L';
					leftThumb = num;
				} else {
					answer += 'R';
					rightThumb = num;
				}
			}
		}
	});
	return answer;
}
