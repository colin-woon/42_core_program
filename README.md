- **.git_checkout** - the actual .git configurations for my passed project, just rename to .git to see `git logs` for commit history

# My 42 Projects
Contains submodules for each 42 project that I did


## To clone all projects
```
git clone --recursive https://github.com/colin-woon/42_core_program.git
```

## If you cloned without --recursive
```
git clone https://github.com/colin-woon/42_core_program.git
```

### Changing all projects to the main branch
```
git submodule update --remote --merge
```

### Changing specific projects to the main branch
```
git submodule update --remote --merge <path/to/submodule>
```

### Add new submodule
```
git submodule add <repository_url> <submodule_path>
```
