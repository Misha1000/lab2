#include <Referee.hpp>

#include <iostream>
#include <fstream>

#include <experimental/filesystem>

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

	Referee referee;
	for (auto const& file : std::experimental::filesystem::directory_iterator(av[1]))
	{
		referee.process_scores_in_file(file.path());
	}

	std::string file_to_write_result("results.csv");
	{
		std::ofstream ofs(file_to_write_result);
		referee.print_results(ofs);
	}

	return 0;
}