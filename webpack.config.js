const path = require('path')
const HtmlWebpackPlugin = require('html-webpack-plugin')

module.exports = {
  // mode: "development",
  cache: true,
  entry: './src/Index.bs.js',
  output: {
    path: path.join(__dirname, 'build'),
    filename: 'index.js'
  },
  plugins: [
    new HtmlWebpackPlugin({
      template: './static/index.html',
      filename: 'index.html',
      inject: true
    })
  ],
  devServer: {
    contentBase: [
      path.join(__dirname, 'static'),
      path.join(__dirname, 'build')
    ],
    historyApiFallback: true,
    open: true,
    inline: true,
    port: 3333,
    watchContentBase: true,
    watchOptions: {
      aggregateTimeout: 300,
      poll: 1000
    }
  }
}
