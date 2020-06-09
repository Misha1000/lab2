#include <iostream>

namespace {
	void check_usage(int ac, char **av)
	{
		if (ac != 2)
		{
			std::cout << "Usage:\t" << av[0] << " dir_name" << std::endl;
			std::cout << "\t\t\tdir_name - path to dir with input .csv files." << std::endl;
			exit(1);
		}
	}
}// namespace

int		main(int ac, char **av)
{
	check_usage(ac, av);
	return 0;
}