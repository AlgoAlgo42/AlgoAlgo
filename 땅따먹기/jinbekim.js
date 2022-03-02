function solution(land) {
	const landLength = land.length;
	for (let i = 1; i < landLength; i++) {
		land[i][0] += Math.max(land[i - 1][1], land[i - 1][2], land[i - 1][3]);
		land[i][1] += Math.max(land[i - 1][0], land[i - 1][2], land[i - 1][3]);
		land[i][2] += Math.max(land[i - 1][0], land[i - 1][1], land[i - 1][3]);
		land[i][3] += Math.max(land[i - 1][0], land[i - 1][1], land[i - 1][2]);
	}
	return Math.max(
		land[landLength - 1][0],
		land[landLength - 1][1],
		land[landLength - 1][2],
		land[landLength - 1][3]
	);
}

console.log(
	solution([
		[1, 2, 3, 5],
		[5, 6, 7, 8],
		[4, 3, 2, 1],
	]),
	'should be 16.'
);
