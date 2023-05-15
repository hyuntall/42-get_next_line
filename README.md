# 42-get_next_line

42-get_next_line은 42 Seoul의 과정에서 진행되는 프로젝트로, 파일 디스크립터에서 텍스트를 읽어오는 함수를 구현하는 것을 목표로 합니다. 이 프로젝트는 파일에서 한 번에 한 줄씩 읽어오는 기능을 제공하여 효율적인 텍스트 처리를 가능하게 합니다.

## 주요 특징

- `get_next_line` 함수의 구현: 42-get_next_line은 파일 디스크립터에서 텍스트를 읽어오는 `get_next_line` 함수를 구현합니다. 이 함수를 사용하여 파일에서 한 줄씩 읽을 수 있으며, 파일의 끝에 도달하거나 에러가 발생할 때까지 반복적으로 호출할 수 있습니다.
- 파일 디스크립터 관리: 42-get_next_line은 여러 파일 디스크립터를 동시에 관리할 수 있습니다. 각 파일마다 독립적인 상태를 유지하고, `get_next_line` 함수를 호출하여 각 파일의 텍스트를 읽어올 수 있습니다.
- 유연한 버퍼 크기 조정: `get_next_line` 함수는 내부 버퍼를 사용하여 텍스트를 읽어오는데, 이 버퍼의 크기는 필요에 따라 조정할 수 있습니다. 적절한 버퍼 크기를 선택하면 메모리 사용량과 I/O 성능을 최적화할 수 있습니다.

## 사용 방법

1. 프로젝트를 클론합니다:

```shell
git clone https://github.com/hyuntall/42-get_next_line.git
```

2. 프로젝트 폴더로 이동합니다:

```shell
cd 42-get_next_line
```

3. `get_next_line` 함수를 사용할 소스 파일에 헤더 파일을 포함합니다:

```c
#include "get_next_line.h"
```

4. `get_next_line()` 함수를 호출하여 파일에서 텍스트를 읽어옵니다. 호출할 때마다 파일에서 한 줄씩 읽어옵니다. 함수의 반환 값은 성공적으로 한 줄을 읽었을 때는 1, 파일의 끝에 도달했을 때는 0, 에러가 발생했을 때는 -1입니다.

```c
int get_next_line(int fd, char **line);
```

5. 필요한 파일 디스크립터를 열고 `get_next_line()` 함수를 호출하여 텍스트를 읽어옵니다. 읽어온 텍스트는 `line` 매개변수로 전달받은 문자열 포인터에 저장됩니다.

6. 파일을 모두 읽었거나 더 이상 필요하지 않을 때, 파일 디스크립터를 닫아 리소스를 정리합니다.

## 사용 예시
```C
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
    int fd;
    char *line;

    // 파일을 열고 파일 디스크립터를 얻습니다.
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일에서 한 줄씩 읽어옵니다.
    int ret;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("읽은 줄: %s\n", line);
        // line 메모리를 해제합니다.
        free(line);
    }

    // get_next_line의 반환 값이 0이면 파일의 끝에 도달한 것입니다.
    if (ret == 0)
    {
        printf("파일의 끝에 도달했습니다.\n");
    }
    // 반환 값이 -1이면 에러가 발생한 것입니다.
    else if (ret == -1)
    {
        printf("에러가 발생했습니다.\n");
    }

    // 파일 디스크립터를 닫습니다.
    close(fd);

    return 0;
}

```
