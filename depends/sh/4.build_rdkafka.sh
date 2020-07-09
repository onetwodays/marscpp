set -ex
# cmake first
git clone https://github.com/edenhill/librdkafka.git
cd librdkafka

  # Or, to automatically install dependencies using the system's package manager:
  # ./configure --install-deps
  # Or, build dependencies from source:
  # ./configure --install-deps --source-deps-only

./configure && make -j8 && sudo make install

cd ..
mv librdkafka ~/pkg/