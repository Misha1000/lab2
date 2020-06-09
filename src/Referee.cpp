#include <Referee.hpp>

#include <fstream>
#include <sstream>
#include <set>
#include <utility>

namespace {
	struct scores_table_comparator
	{
		bool	operator()(std::pair<std::string, int> const& left, std::pair<std::string, int> const& right)
		{
			if (left.second != right.second)
			{
				return left.second > right.second;
			}

			return left.first > right.first;
		}
	};
}// namespace

/*
**	public methods
*/

void	Referee::process_scores_in_file(std::string const& file_name)
{
	std::ifstream ifs(file_name);

	int count_of_further_lines;
	ifs >> count_of_further_lines;

	std::string line;
	for (int i = 0; i < count_of_further_lines && std::getline(ifs, line); ++i)
	{
		_process_one_country_line(line);
	}
}

void	Referee::print_results(std::ostream& os)
{
	std::set<std::pair<std::string, int>, scores_table_comparator> to_sort(_m_scores_table.begin(), _m_scores_table.end());

	const int places_to_print = 10;

	int i = 0;
	for (auto const& it : to_sort)
	{
		if (i >= places_to_print)
		{
			break;
		}

		os << it.first << ": " << it.second << std::endl;
		++i;
	}
}



/*
**	private methods
*/

void	Referee::_process_one_country_line(std::string const& line)
{
	std::stringstream ss(line);

	std::string country_name;
	std::getline(ss, country_name, ',');

	std::size_t total_scores{};

	std::string token;
	while (std::getline(ss, token, ','))
	{
		total_scores += std::stoull(token);
	}

	_m_scores_table[country_name] += total_scores;
}