# ベースイメージ
FROM ubuntu:latest

# パッケージの更新と必要なパッケージのインストール
RUN apt-get update && apt-get install -y \
    build-essential 

# その他必要なパッケージ (例: gdb, valgrind)
RUN apt-get install -y git 

# 作業ディレクトリの作成         
WORKDIR /app

# アプリケーションのソースコードをコピー
COPY . .

# アプリケーションのビルド
CMD /bin/sh -c "echo '準備完了' && sleep infinity"