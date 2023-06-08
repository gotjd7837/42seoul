# Born2beroot
Summary: This document is a System Administration related exercise.
version : 2

**요약 : 이 과제는 시스템(운영체제) 관리 관련 실습입니다.
버전 : 2**


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
로그인한 유저 그룹 확인
- id [사용자명]

사용자 생성
- sudo adduser [사용자명]

패스워드 생성 규칙
- sudo vi /etc/login.defs
- sudo vim /etc/pam.d/common-password
- 다음 두 파일을 수정해서 패스워드 정책 수립

새로운 그룹 생성
- sudo addgroup [그룹명]

그룹 추가
- sudo usermod -G sudo,user42 [사용자명]
- - 사용자가 속한 그룹을 sudo,user42로 변경


## 호스트명과 파티션

호스트명 수정
- sudo hostnamectl set-hostname [호스트명]

가상 머신의 파티션 확인
- lsblk

LVM이 어떻게 동작하는지 ?

## sudo
sudo 프로그램이 잘 설치되어 있는지 ?
- sudo apt install sudo
- 설치 되어있는지 확인

새로만든 유저를 sudo 그룹에 할당
- sudo usermod -G sudo,user42 [사용자명]
- 이때 이미 할당됨

sudo를 사용하는 이유와 동작 예시 제시
- sudo는 일시적으로 관리자 권한을 빌려서 사용하는 명령어임
- 관리자 권한은 권한이 무한대임 고로 해커들이 최우선적으로 원하는 것이 관리자 권한을 얻는 것이다 sudo권한을 일시적으로 빌려서 사용하게 함으로써 계정 정보가 노출 당해도 관리자 권한까지 노출당하지 않도록 해서 보안을 강화하는 것임

과제에서 요구하는 sudo 규칙에 대한 구현
- sudo visudo 파일에서 볼 수 

"/var/log/sudo/" 폴더가 존재하는 지, 그리고 그것이 최소한 한 개의 파일을 갖는 지 확인

이 폴더 속 파일들의 내용을 확인할 때, sudo와 함께 사용된 명령어들의 기록을 볼 수 있어야함
- /var/log/sudo/sudo.log 파일에서 볼 수 있음

## UFW
UFW란 ?
- 데비안의 방화벽 설정 프로그램
- 방화벽은 원치 않는 트래픽으로부터 네트워크를 보호하는 네트워크 보안 솔루션

UFW를 사용함으로써 얻는 장점
- UFW를 통해 보안을 강화할 수 있다. 기본적으로 모든 연결을 거부하도록 설정하고 필요한 포트만 열어서 사용할 수 있다.

UFW의 규칙, 4242포트
- sudo ufw status verbose
- 들어오는 것 deny 나가는 것 allow
- sudo ufw allow 4242
- 4242포트 허용

8080포트 열기
- sudo ufw allow 8080

8080포트 닫기
- sudo ufw deny 8080

## SSH
SSH란 ?

SSH의 장점

SSH가 4242포트만을 사용하는지 ?

root유저로 ssh연결을 차단

## cron
유닉스 계열 컴퓨터의 잡 스케쥴러이다.
특정한 작업을 고정된 시간에 실행할 수 있도록 해준다.
wall 명령어를 사용해서 로그인된 모든 사용자에게 메세지를 

- sudo crontab -l 로 크론탭 파일을 cat해서 볼 수 있음
- sudo crontab -e 로 크론탭 파일을 열어줌



$ systemctl status cron.service # status check


$ sudo service cron start # start

$ /etc/init.d/cron start # 멈추기

$ sudo systemctl disable cron # 재부팅 후에 멈추기

$ sudo systemctl enable cron # 재부팅 후에 재시작

$ /etc/init.d/cron stop # stop

$ sudo service cron stop # stop

$ sudo crontab -e # edit

$ sudo crontab -l # list








