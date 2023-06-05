# Born2beroot
Summary: This document is a System Administration related exercise.
version : 2

**요약 : 이 과제는 시스템(운영체제) 관리 관련 실습입니다.
버전 : 2**

## Introduction
This project aims to introduce you to the wonderful world of virtualization.

**이 과제에서는 여러분에게 가상화의 멋진 세상을 소개해드리고자 합니다.**


You will create your first machine in VirtualBox (or UTM if you can’t use VirtualBox) under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules

**여러분은 VirtualBox를 통해서 (불가능하다면 UTM을 통해서) 주어진 요구사항들에 따라 첫 가상 머신을 만들 것입니다. 그리고 나면, 과제를 마칠 때 즈음 여러분은 엄격한 규칙들로 이루어진 자신만의 운영체제를 구현할 수 있을 것입니다.**

## Mandatory part
This project consists of having you set up your first server by following specific rules.

**이 과제는 여러분의 첫 서버를 특정 규칙들에 따라 구현하게끔 할 것입니다.**


⚠️Since it is a matter of setting up a server, you will install the minimum of services. For this reason, a graphical interface is of no use here. It is therefore forbidden to install X.org or any other equivalent graphics server. Otherwise, your grade will be 0.

⚠**서버를 구성하는 것이 주요 사항이기 때문에, 최소한의 서비스만 설치하셔야 합니다. 이 때문에, 그래픽 인터페이스는 이 과제에서 사용되지 않습니다. 그래픽 인터페이스를 사용할 수 없으므로, X.org나 그에 상응하는 다른 그래픽 서버들은 설치할 수 없습니다. 만약 설치했다면, 0점을 받게될 것입니다.**


You must choose as an operating system either the latest stable version of Debian (no testing/unstable), or the latest stable version of Rocky. Debian is highly recommended if you are new to system administration.

**여러분은 가장 최신의 stable 버전인 Debian(testing/unstable 제외) 혹은, 가장 최신의 stable 버전인 Rocky 둘 중에 한 운영체제를 선택하셔야 합니다. 만약 시스템 관리가 처음이시라면, Debian 을 강력히 추전드립니다.**


ℹ️ setting up Rocky is quite complex. Therefore, you don’t have to set up KDump. However, SELinux must be running at startup and its configuration has to be adapted for the project’s needs. AppArmor for Debian must be running at startup too.

ℹ️ **Rocky를 세팅하는 것은 꽤 복잡합니다. 그렇기 때문에, 여러분은 KDump까지 설치할 필요는 없습니다. 하지만, SELinux는 실행되었을 때 반드시 작동하고 있어야하고, SELinux은 과제에서 요구하는 사항에 따라 구성되어있어야 합니다. Debian의 경우에는 AppArmor가 실행 시에 작동하고있어야 합니다.**


ℹ️During the defense, you will be asked a few questions about the operating system you chose. For instance, you should know the differences between aptitude and apt, or what SELinux or AppArmor is. In short, understand what you use!

**평가를 진행하면서, 여러분은 여러분이 선택한 운영체제에 대한 질문들을 받게 될 것입니다. 예를 들면, apt와 aptitude의 차이점, 혹은 SElinux 또는 AppArmor가 무엇인지 등 말이죠. 요약하자면, 여러분이 사용하고 있는 것이 무엇인지 아셔야 합니다!**


A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.

**SSH 서비스는 4242포트에서만 작동해야 합니다. 보안적인 이유로, root로는 SSH에 연결할 수 없어야 합니다.**


ℹ️The use of SSH will be tested during the defense by setting up a new account. You must therefore understand how it works.

**SSH의 용법은 평가를 진행하면서, 생성된 새 계정을 통해 테스트됩니다. 그러니 SSH가 어떻게 작동하는지 아셔야 합니다.**


You have to configure your operating system with the UFW (or firewalld for Rocky) firewall and thus leave only port 4242 open.

**여러분은 UFW(Rocky인 경우 firewalld) 방화벽을 여러분의 운영체제에 구성해놓으셔야 하고, 그에 따라 4242 포트만 열어놓으셔야 합니다.**


ℹ️Your firewall must be active when you launch your virtual machine. For Rocky, you have to use firewalld instead of UFW.

**여러분이 가상 머신을 켰을 때, 방화벽이 작동하고 있어야 합니다. Rocky의 경우에는, UFW 대신 firewalld가 작동하고 있어야 합니다.**



The hostname of your virtual machine must be your login ending with 42 (e.g. wil42). You will have to modify this hostname during your evaluation.

**여러분의 가상 머신의 hostname은 여러분의 42로 끝나는 여러분의 아이디여야 합니다(예시 : wil42). 평가 중에 여러분은 hostname을 수정하셔야 할 겁니다.**

You have to implement a strong password policy.

**여러분은 강력한 패스워드 정책을 구현하셔야 합니다.**

You have to install and configure sudo following strict rules.

**여러분은 엄격한 규칙에 따라서 sudo를 설치하고, 구성하셔야 합니다.**

In addition to the root user, a user with your login as username has to be present.

**root 유저에 더해서, 여러분의 아이디에 따른 유저도 존재해야 합니다.**

This user has to belong to the user42 and sudo groups.

**이 유저는 user42와 sudo 그룹에 속해있어야 합니다.**

ℹ️During the defense, you will have to create a new user and assign it to a group.

**평가 중, 여러분은 새 유저를 생성하고, 그룹에 가입시켜야 합니다.**


To set up a strong password policy, you have to comply with the following requirements:

**강력한 패스워드 규정을 구성하는 데에 있어서, 여러분은 다음과 같은 요구사항들을 적용해야 합니다:**

Your password has to expire every 30 days.

**패스워드는 매 30일마다 만료되어야 한다.**

The minimum number of days allowed before the modification of a password will be set to 2.

**패스워드 변경 후에 수정이 가능한 최소 경과일 수는 2일이어야 한다.**

The user has to receive a warning message 7 days before their password expires.

**유저는 패스워드 만료 7일 전에 경고 메시지를 받아야 한다.**

Your password must be at least 10 characters long. It must contain an uppercase letter, a lowercase letter, and a number. Also, it must not contain more than 3 consecutive identical characters.

**패스워드는 대문자, 소문자, 숫자를 포함한 최소 10글자 이상이어야 한다. 또, 반복되는 글자가 3글자 초과인 경우는 포함되지 않아야 한다.**

The password must not include the name of the user.

**패스워드는 유저의 이름을 포함하지 않아야 한다.**

The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.

**다음 규칙은 root 패스워드에 적용되지 않습니다 : 현재 패스워드는 최소 7글자 이상이 이전 패스워드와 달라야 한다.**

Of course, your root password has to comply with this policy.

**당연히, root 패스워드에도 이 규정은 적용되어야 합니다.**

⚠️After setting up your configuration files, you will have to change all the passwords of the accounts present on the virtual machine, including the root account.

⚠️**패스워드 구성 파일들을 설정한 후에, 여러분은 root 계정을 포함한 가상 머신에 있는 모든 비밀번호를 바꾸셔야 할 겁니다.**


To set up a strong configuration for your sudo group, you have to comply with the following requirements:

**여러분의 sudo 그룹의 강력한 규정을 구성하기 위해서, 다음의 요구사항들을 적용해야 합니다:**

Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.

**sudo를 사용하기 위한 인증에서, 잘못된 비밀번호 입력의 경우 3번의 시도로 제한되어야 한다.**

A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.

**sudo 사용 중, 잘못된 패스워드로 인한 에러가 발생했을 때에 여러분이 설정한 메시지가 출력되어야 한다.**

Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.

**sudo를 통한 모든 동작(입출력)은 저장되어야 합니다. log 파일들은 /var/log/sudo 폴더에 저장되어야 한다.**

The TTY mode has to be enabled for security reasons.

**보안적인 이유로 인해, TTY 모드는 적용되어 있어야 한다.**

For security reasons too, the paths that can be used by sudo must be restricted.

**같은 이유로, sudo를 사용할 수 있는 경로는 제한되어있어야 한다.**

Example:

경로 예시:
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

Finally, you have to create a simple script called monitoring.sh. It must be developed in bash.

**최종적으로, 여러분은 monitoring.sh라고 하는 간단한 스크립트를 작성해야 합니다. 스크립트는 bash로 작성되어야 합니다.**

At server startup, the script will display some information (listed below) on all terminals every 10 minutes (take a look at wall). The banner is optional. No error must be visible.
**서버를 시작할 때, 스크립트는 아래에 나열된 정보들을 모든 터미널에 매 10분마다 표시해야 합니다(wall을 잘 살펴보세요). 배너는 선택사항입니다. 에러는 표시되지 않아야 합니다.**

Your script must always be able to display the following information:

**여러분의 스크립트는 다음의 정보들을 항상 표시할 수 있어야 합니다.**

The architecture of your operating system and its kernel version.
- 운영체제와 커널의 버전에 대한 구조

The number of physical processors
- 물리 프로세서들의 수


The number of virtual processors.
- 가상 프로세서들의 수


The current available RAM on your server and its utilization rate as a percentage.
- 현재 서버에서 사용가능한 RAM과 백분율로 표현된 사용률.


The current available memory on your server and its utilization rate as a percentage.
- 현재 서버에서 사용가능한 memory와 백분율로 표현된 사용률.

The current utilization rate of your processors as a percentage.
- 백분율로 표현된 프로세서들의 현재 사용률.


The date and time of the last reboot.
- 마지막으로 재시작된 날짜와 시간.


Whether LVM is active or not.
- LVM의 활성화 여부.


The number of active connections.
- 활성화된 연결들의 개수.


The number of users using the server.
- 서버를 사용하고 있는 유저의 수.


The IPv4 address of your server and its MAC (Media Access Control) address.
- 서버의 IPv4 주소와 MAC 주소.


The number of commands executed with the sudo program
- sudo 프로그램으로 실행된 명령의 수.


ℹ️During the defense, you will be asked to explain how this script works. You will also have to interrupt it without modifying it. Take a look at cron.

**ℹ️평가 중, 여러분은 스크립트가 어떻게 동작하는지 질문받게 될 겁니다. 또, 스크립트를 수정하지 않고 그 동작을 중지시켜야 합니다. cron을 잘 살펴보세요.**

# 개념 정리

## 가상머신
가상 머신은 물리적 하드웨어 시스템에 구축되어 자체 cpu,메모리, 네트워크 인터페이스 및 스토리지를 갖추고 가상 컴퓨터 시스템으로 작동하는 환경이다.
하이퍼 바이저라고 불리는 소프트웨어를 이용해서 물리적 리소스를 일정 분리해서 마치 하나의 물리적 머신이 더 생긴 것처럼 가상 머신으로 활용할 수 있게한다.

## centOS와 데비안
리눅스는 unix 운영체제를 기반으로 만들어진 오픈소스 기반 운영체제이다.
리눅스는 오픈소스 기반이기 때문에 누구든 수정 및 배포가 가능하므로, 수많은 버전의 리눅스가 존재한다. 대표적으로 데비안 계열과 레드햇 계열이 있다

레드햇 계열 리눅스는 레드햇이라는 회사에서 배포한 리눅스 배포판이다 운영체제가 자발적인 커뮤니티에 의해 발전한게 아닌 회사에서 관리하기 때문에 패치가 빠르고 툴의 성능이 우수하다.
CentOS는 레드햇이 공개한 리눅스를 그대로 가져와서 레드햇의 브랜드와 로고만 제거한 배포판이다. 기업용으로 많이 사용된다

데비안은 레드햇보다 먼저 온라인 커뮤니티를 통해 제작되어 배포된 운영체제이다 무료이므로 개인 사용자용으로 인기가 많다.

## aptitude와 apt
aptitude와 apt모두 데비안의 패키지를 관리자 이다. 패키지 관리란 새로운 소프트웨어를 설치, 업데이트, 삭제 등을 하는 일을 말한다.
aptitude가 apt보다 더 많은 기능을 제공한다. 예를 들면 하나의 패키지를 삭제한다고 했을 때 이 패키지와 관련된 패키지를 전부 같이 삭제해주는 등 더 많은 기능을 제공하는 패키지 관리자이다.

## APPArmor
apparmor는 리눅스 애플리케이션 보안 시스템으로 내외부적 위협으로부터 운영체제와 애플리케이션을 능동적으로 보호하는 리눅스 커널 보안 모듈이다.
MAC 접근 통제 방법을 사용해서 기존의 DAC 접근 통제 방법을 보완해준다.

운영체제에서 접근 통제란 디렉터리나 파일, 네트워크 소켓과 같은 시스템 자원을 적절한 권한을 가진 사용자나 그룹만 접근하고 사용할 수 있게 통제하는 것을 말한다

MAC : 미리 정한 정책과 보안 등급에 의거하여 접근 통제
      관리자만이 객체의 보안레벨, 주체의 보안등급을 수정 가능
      높은 보안을 요구하는 정보는 낮은 보안 수준의 주체가 접근 할 수 없음
      
## 기본 설정 확인
UFW는 데비안의 기본적인 방화벽이다.
**sudo ufw status** 명령어로 작동 확인이 가능하다

SSH 서비스
**systemctl status ssh** 로 실행 확인이 가능하다.

## 사용자 설정







