function solution(absolutes, signs) {
	return absolutes.reduce((prev, curr, idx) => {
		const signIdx = signs[idx] === true ? 1 : -1;
		return prev + signIdx * curr;
	}, 0);
}
