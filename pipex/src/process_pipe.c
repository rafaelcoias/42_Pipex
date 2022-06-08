#include "../include/pipex.h"

static void process_father(t_data *data)
{
    dup2(data->fd_pipe[0], STDIN_FILENO);
    close(data->fd_pipe[1]);
    close(data->fd_pipe[0]);
}

static void process_child(t_data *data)
{
    char    **args;

    args = ft_split(data->cmd1, ' ');
    dup2(data->fd_pipe[1], STDOUT_FILENO);
    close(data->fd_pipe[0]);
    close(data->fd_pipe[1]);
    if (execve(data->path_cmd1, args, data->envp) == -1)
        error_msg(EXEC_ERROR);
}

void    process_pipe(t_data *data)
{
    char    **args;
    int     pid_child;
    int     pid2_child;

    pid_child = fork();
    if (pid_child == -1)
        error_msg(FORK_ERROR);
    if (!pid_child)
        process_child(data);
    else
        process_father(data);
    waitpid(pid_child, 0, 0);
    args = ft_split(data->cmd2, ' ');
    dup2(data->fd_out, STDOUT_FILENO);
    pid2_child = fork();
    if (pid2_child == -1)
        error_msg(FORK_ERROR);
    if (!pid2_child)
        if (execve(data->path_cmd2, args, data->envp) == -1)
            error_msg(EXEC_ERROR);
    waitpid(pid2_child, 0, 0);
}