function solution(maps) {
	const yMax = maps.length - 1,
		xMax = maps[0].length - 1;
	const YCORD = 0,
		XCORD = 1;

	const q = [];
	const visited = Array.from({ length: yMax + 1 }, () =>
		Array(xMax + 1).fill(false)
	);
	q.push([0, 0]);
	while (q.length) {
		const cord = q.shift();
		const yCord = cord[YCORD];
		const xCord = cord[XCORD];

		if (yCord > yMax || xCord > xMax || yCord < 0 || xCord < 0) continue;
		if (yCord === yMax && xCord === xMax) return maps[yMax][xMax];
		for (let i = -1; i <= 1; ++i) {
			for (let j = -1; j <= 1; ++j) {
				if ((i ^ j) === 1 || (i ^ j) === -1) {
					if (
						yCord + j >= 0 &&
						xCord + i >= 0 &&
						yCord + j <= yMax &&
						xCord + i <= xMax
					) {
						if (visited[yCord + j][xCord + i]) continue;
						if (maps[yCord + j][xCord + i] === 1) {
							maps[yCord + j][xCord + i] = maps[yCord][xCord] + 1;
							q.push([yCord + j, xCord + i]);
							visited[yCord + j][xCord + i] = true;
						} else if (maps[yCord + j][xCord + i] !== 0) {
							maps[yCord + j][xCord + i] =
								maps[yCord + j][xCord + i] >
								maps[yCord][xCord] + 1
									? maps[yCord][xCord] + 1
									: maps[yCord + j][xCord + i];
							q.push([yCord + j, xCord + i]);
							visited[yCord + j][xCord + i] = true;
						}
					}
				}
			}
		}
	}
	return -1;
}
