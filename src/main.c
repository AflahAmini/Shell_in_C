int main(int argc, char **argv)
{
  // Load config files, if any.

  // Run command loop.
  lsh_loop();

  // Perform any shutdown/cleanup.

  return EXIT_SUCCESS;
}

void lsh_loop(void)
{
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    //call a function to read a line
    line = lsh_read_line();

    //call a function to split the line into args
    args = lsh_split_line(line);

    //execute the args
    status = lsh_execute(args);

    free(line);
    free(args);
  } while (status);
}