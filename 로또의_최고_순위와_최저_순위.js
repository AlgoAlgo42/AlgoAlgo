function solution(lottos, win_nums) {
	let joker = 0;
	let match = 0;
	const rank = [6, 6, 5, 4, 3, 2, 1];

	lottos.forEach((val) => {
		if (val === 0) joker++;
		if (win_nums.includes(val)) match++;
	});

	return [rank[match + joker], rank[match]];
}
