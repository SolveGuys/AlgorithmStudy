const int NOT_YET = -1;
long* Ns;// [31] ;

long tile(int ith)
{
	if (ith == 1)
		return 1;

	long& tile_ith = Ns[ith];

	if (tile_ith != NOT_YET)
		return tile_ith;

	//blooming from center
	tile_ith = 2 * tile(ith - 2) + tile(ith - 1);

	return tile_ith;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	/*
	//Ns[0] = 0;
	Ns[1] = 1;
	Ns[2] = 3;
	Ns[3] = 3;
	*/

	int N;
	std::cin >> N;
	Ns = new long [N] ;
	memset(Ns, NOT_YET, sizeof(long) * N);
	for (int i = 0; i < N; i++)
		std::cout << Ns[i] << ' ';
	


	delete Ns;
	return 0;
}