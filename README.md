- **.git_checkout** - the actual .git configurations for my passed project, just rename to .git to see `git logs` for commit history

# My 42 Projects
Contains submodules for each 42 project that I did  
  

## To clone all projects
```
git clone --recursive git@github.com:colin-woon/hackathons.git
```

## To clone specific projects
```
git clone git@github.com:colin-woon/hackathons.git
git submodule update --init <file_directory>
```
```
EXAMPLE:
git submodule update --init epfence_devmatch2024/
```

### If you decide to clone all projects
```
git submodule update --init --recursive
```

