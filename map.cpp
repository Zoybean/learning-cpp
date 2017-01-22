//TODO: figure out how tf to make this work. need to know the size of the array I'm returning
template <typename R, typename D, size_t N>
std::array<R,N> map(R (*func)(D), D (& array)[N])
//R map(R (*func)(D), D (& array)[N])[N]
//std::array<R,N>& map(R (*func)(D), std::array<D,N> const& array)
{
	//R mapped[N] = new R[N];
	std::array<R,N> mapped = new std::array<R,N>;
	//std::array<R,N> mapped();
	for (int ii = 0; ii < N; ++ ii)
	{
		mapped[ii] = (*func)(array[ii]);
	}
	return mapped;
}
int plusone(int n)
{
	return n+1;
}

int main (int argc, char **argv)
{
	int array2[3], array[] = {1,2,3};
	array2 = map<int,int,3>(&plusone, array);
	return 0;
}
