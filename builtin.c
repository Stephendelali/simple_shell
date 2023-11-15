#include "shell.h"

/**
 * _myexit - exits the shell
 * @inf: Structure that might support arguments. utilized to keep the function
 *          prototype consistent.
 *  Return: exits
 *         (0) if info.argv[0]"
 */
int _myexit(info_t *inf)
{
	int exitchec;

	if (inf->argv[1])
	{
		exitchec = _erratoi(inf->argv[1]);
		if (exitchec == -1)
		{
			inf->status = 2;
			print_error(inf, "Illegal number: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _mycd - modifies the process's current directory
 * @inf:Structure that might support arguments.utilized to preserve
 *          the prototype of the constant function
 *  Return: Always 0
 */
int _mycd(info_t *inf)
{
	char *c, *dir, buffer[1024];
	int chdir_ret;

	c = getcwd(buffer, 1024);
	if (!c)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		dir = _getenv(inf, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(inf, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(c);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(inf, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(inf->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(inf, "can't cd to ");
		_eputs(inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
		_setenv(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - modifies the process's current directory
 * @inf: Structure that might support arguments. utilized to preserve
 *          the prototype of the constant function
 *  Return: Always 0
 */
int _myhelp(info_t *inf)
{
	char **arg_array;

	arg_array = inf->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
