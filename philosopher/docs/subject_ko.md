# PHILOSOPHER

## Common Instructions
- 당신의 프로젝트는 C로 작성되어야 합니다.

- 프로젝트는 Norm에 따라 작성되어야 합니다. 보너스 파일/함수가 있다면 Norm 체크에 포함되며, Norm 오류가 있으면 0점을 받게 됩니다.
- 함수가 예기치 않게 종료되지 않아야 합니다 (segmentation fault, bus error, double free 등), 정의되지 않은 동작을 제외하고는. 이러한 경우, 프로젝트는 비정상적으로 간주되며, 평가 중에 0점을 받게 됩니다.
- 모든 힙 할당된 메모리 공간은 필요할 때 적절하게 해제되어야 합니다. 누수가 있으면 용납되지 않습니다.
- 주제가 요구하는 경우, Makefile을 제출해야 합니다. 이 Makefile은 소스 파일을 -Wall, -Wextra 및 -Werror 플래그와 함께 필요한 출력으로 컴파일하고, cc를 사용해야 하며, Makefile은 다시 링크하지 않아야 합니다.
- Makefile은 최소한 $(NAME), all, clean, fclean 및 re 규칙을 포함해야 합니다.
- 보너스를 프로젝트에 추가하려면, Makefile에 보너스 규칙을 포함해야 합니다. 이 규칙은 프로젝트의 주요 부분에서 금지된 모든 헤더, 라이브러리 또는 함수를 추가합니다. 주제가 다른 것을 명시하지 않으면 보너스는 _bonus.{c/h}와 같은 다른 파일에 있어야 합니다. 필수 부분과 보너스 부분 평가는 별도로 이루어집니다.
- 프로젝트에서 libft를 사용할 수 있는 경우, 해당 소스와 연결된 Makefile을 libft 폴더에 복사해야 합니다. 프로젝트의 Makefile은 이 Makefile을 사용하여 라이브러리를 컴파일한 다음, 프로젝트를 컴파일해야 합니다.
- 프로젝트에 대한 테스트 프로그램을 작성하는 것을 권장합니다. 이 작업은 제출하거나 평가되지 않겠지만, 작업을 쉽게 테스트하고 동료의 작업을 테스트할 수 있는 기회를 제공합니다. 특히 방어 중에 이러한 테스트를 유용하게 사용할 수 있습니다. 방어 중에는 여러분의 테스트나 평가하는 동료의 테스트를 자유롭게 사용할 수 있습니다.
- 작업물을 지정된 git 저장소에 제출해야 합니다. 채점은 git 저장소의 작업물만을 대상으로 합니다. Deepthought가 작업물을 채점하게 될 경우, 동료 평가 후에 수행됩니다. 만약 채점 중에 어떤 섹션에서 오류가 발생하면, 채점은 중단됩니다.	
#
## Global rules
*필수 파트와 보너스 파트를 위한 프로그램을 각각 작성해야 합니다. 두 프로그램 모두 다음 규칙을 준수해야 합니다:*
* 전역 변수는 사용할 수 없습니다!
* 프로그램은 다음 인수를 받아야 합니다: 철학자 수, 죽는 시간, 먹는 시간, 자는 시간, [각 철학자가 먹어야 하는 횟수]

	- 철학자 수: 철학자와 포크의 수입니다.

	- 죽는 시간 (밀리 초 단위): 철학자가 마지막 식사를 시작한 후 time_to_die 밀리 초가 지나거나 시뮬레이션 시작 후 time_to_die 밀리 초가 지나면 철학자가 죽습니다.
	- 먹는 시간 (밀리 초 단위): 철학자가 식사하는 데 걸리는 시간입니다. 이 동안 두 개의 포크를 잡아야 합니다.
	- 자는 시간 (밀리 초 단위): 철학자가 자는 시간입니다.
	- 각 철학자가 먹어야 하는 횟수 (선택적 인수): 모든 철학자가 number_of_times_each_philosopher_must_eat 번 이상 먹었을 때 시뮬레이션이 종료됩니다. 지정되지 않은 경우 철학자가 죽을 때 시뮬레이션이 종료됩니다.

* 각 철학자는 1부터 number_of_philosophers까지의 번호를 가집니다.

* 철학자 번호 1은 철학자 번호 number_of_philosophers의 옆에 앉습니다. 다른 철학자 번호 N은 철학자 번호 N - 1과 철학자 번호 N + 1 사이에 앉습니다.

*프로그램의 로그에 대해서:*
* 철학자의 상태 변경은 다음과 같은 형식으로 표시되어야 합니다:

	- timestamp_in_ms X has taken a fork 
	
	- timestamp_in_ms X is eating
	- timestamp_in_ms X is sleeping
	- timestamp_in_ms X is thinking
	- timestamp_in_ms X died  

*timestamp_in_ms는 현재 밀리 초 단위의 타임스탬프로 대체되며, X는 철학자의 번호로 대체됩니다.*

* 표시된 상태 메시지는 다른 메시지와 혼동되어서는 안 됩니다.

* 철학자가 사망한 사실을 알리는 메시지는 실제 철학자의 사망 후 10ms 이내에 표시되어야 합니다.
* 다시 한 번, 철학자들은 사망을 피해야 합니다!  

*<span style="color:pink">
프로그램은 데이터 레이스를 가지지 않아야 합니다..</span>*
#
## Mandatory part
|category|rules|
|:--|:--|
|**Program name**|philo|
|**Turn in files**|Makefile, *.h, *.c, in directory philo/|
|**Makefile**|NAME, all, clean, fclean, re|
|**Arguments**|number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]|
|**External functs.**|memset, printf, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock|
|**Libft authorized**|No|
|**Description**|Philosophers with threads and mutexes|

*필수 파트에 대한 구체적인 규칙은 다음과 같습니다:*

- 각 철학자는 스레드여야 합니다.

- 철학자 쌍 사이에는 한 개의 포크가 있어야 합니다. 따라서 여러 철학자가 있는 경우, 각 철학자는 왼쪽에 포크 하나와 오른쪽에 포크 하나를 가지고 있어야 합니다. 철학자가 한 명인 경우, 테이블 위에는 하나의 포크만 있어야 합니다.
- 철학자들이 포크를 중복해서 사용하지 않도록 각각에 대해 뮤텍스로 포크의 상태를 보호해야 합니다.  
#
## Bonus Part
|category|rules|
|:--|:--|
|Program name|philo_bonus|
|Turn in files|Makefile, *.h, *.c, in directory philo_bonus/|
|Makefile|NAME, all, clean, fclean, re|
|Arguments|number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]|
|External functs.|memset, printf, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink|
|Libft authorized|No|
|Description|Philosophers with processes and semaphores|

*보너스 파트의 프로그램은 필수 파트와 동일한 인수를 사용해야 합니다. 또한 전역 규칙 장의 요구 사항을 준수해야 합니다.*

*보너스 파트의 구체적인 규칙은 다음과 같습니다:*

- 모든 포크는 테이블 가운데에 놓여져야 합니다.

- 포크는 상태를 메모리에 가지지 않고, 사용 가능한 포크의 수는 세마포로 표현됩니다.
- 각 철학자는 프로세스여야 합니다. 그러나 메인 프로세스는 철학자가 되어서는 안 됩니다.  

*<span style="color:pink">
보너스 파트는 필수 파트가 완벽하게 구현되고 정상적으로 작동하는 경우에만 평가됩니다. 완벽하다는 것은 필수 파트가 모든 요구 사항을 완전히 충족하고 오류 없이 작동한 것을 의미합니다. 필수 요구 사항을 모두 충족하지 않은 경우 보너스 파트는 전혀 평가되지 않을 것입니다.</span>*

#
## Submission and peer-evaluation
*과제를 평소와 같이 Git 저장소에 제출하세요. 방어 중에는 저장소 내의 작업만 평가됩니다. 파일 이름이 올바른지 확인하기 위해 두 번 확인하는 것이 좋습니다.* 
- 필수 파트 디렉토리: philo/  
- 보너스 파트 디렉토리: philo_bonus/