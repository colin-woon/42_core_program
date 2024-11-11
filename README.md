- **.git_checkout** - the actual .git configurations for my passed project, just rename to .git to see `git logs` for commit history

# My 42 Projects
Contains submodules for each 42 project that I did


## To clone all projects
```
git clone --recursive https://github.com/colin-woon/42_core_program.git
```

## To clone specific projects
```
git clone https://github.com/colin-woon/42_core_program.git
git submodule update --remote --merge <path/to/submodule>
```
```
EXAMPLE:
git submodule update --remote --merge epfence_devmatch2024/
```

### If you decide to clone all projects
```
git submodule update --remote --merge
```

